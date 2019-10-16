000100190328     F**************************************************************************
000101190328     F*  CUSTOMER18 READ BY NATIVE LANGUAGE (ILE RPG)
000102190328     F*  CONTACTW18 ROW RETRIEVED WITH EMBEDDED SQL
000103190328     F*  DETAIL REPORT LINE INCLUDES INFORMATION FROM CUSTOMER18 AND CONTACTW18
000104190328     F*  SUMMARY REPORT INFORMATION RETRIEVED WITH EMBEDDED SQL STATEMENTS
000105190328     F**************************************************************************
000106190328
000107190404     FCUSTOMER19IF   E             DISK    RENAME(CUSTOMER19:CUSTOMERRF)
000108190328     FQPRINT    O    F  132        PRINTER OFLIND(*INOF) FORMOFL(30) FORMLEN(66)
000109190328
000110190328     D*  H O S T   V A R I A B L E S
000111190404     D CONTACTW19    E DS
000112190328     D ContactTotal    S              5  0
000113190328     D CustomerTotal   S              5  0
000114190328     D UnknownTotal    S              5  0
000115190328     D OldestDate      S               D
000116190328     D MostRecentDate  S               D
000117190328     D User            S             10
000118190328     D Server          S             10
000119190328     D TimeStamp       S               Z
000120190328     D DateIn          S              5  0
000121190328
000122190328     D*  I N D I C A T O R   V A R I A B L E S
000123190328     D IndLastDateC    S              4B 0
000124190328     D IndNextDateC    S              4B 0
000125190328
000126190328     D Dummy           S              1  0
000127190404     D Flag            S              8
000128190328     D NextCallDate    S               D
000129190328     C/EJECT
000130190328     C**************************************************************************
000131190328     C*                        ***   M A I N   R O U T I N E   ***
000132190328     C**************************************************************************
000133190328      /FREE
000134190328                EXSR SummaryInfo;
000135190328                EXCEPT HEADINGS;
000136190404                READ CUSTOMER19;
000137190328                DOW NOT %EOF;
000138190328                    EXSR SQLSelect;
000139190328                    IF *INOF = *ON;
000140190328                       EXCEPT HEADINGS;
000141190328                       *INOF = *OFF;
000142190328                    ENDIF;
000143190328                    EXCEPT DETAIL;
000144190404                   READ CUSTOMER19;
000145190328                ENDDO;
000146190328                EXCEPT TOTALS;
000147190328                *INLR = *ON;
000148190328                RETURN;
000149190328        //*************************************************************************
000150190328        //   S Q L S E L E C T   S U B R O U T I N E
000151190328   //   //********************************************************************
000152190328   //                  BEGSR    SQLSelect ;
000153190328   //    // A row from the contacts table that has the same customer number found in the
000154190328   //    // record read from the CUSTOMER18 file. That row is retrieved to find out the last
000155190328   //    // date called, phone number, comments and the salesperson number.
000156190328   //
000157190328   //    //  The call back interval is added to the last date called to determine the
000158190328   //    //  next date to call.  Since null values may be stored in the last date called
000159190328   //    // indicator variables are used.
000160190328
000161190328                                EXEC SQL
000162190328                                     SELECT PHNLDC + PHNCIT DAYS, PHNLDC,
000163190328                                       CSTPHN,PHNCOM, CSTSLN
000164190328                                     INTO :NextCallDate :IndNextDateC,
000165190328                                          :PHNLDC :IndLastDateC,
000166190328                                          :CSTPHN, :PHNCOM, :CSTSLN
000167190328
000168190404                                     FROM BCI433LIB/CONTACTW19
000169190328                                    WHERE CSTNUM = :CSTNUM;
000170190328
000171190328                                    IF IndLastDateC = -1;
000172190328                                     CSTPHN = 'UNKNOWN DATE';
000173190328                                     NextCallDate = D'9999-09-09';
000174190328                                     PHNLDC = D'9999-09-09';
000175190328
000176190328                                   ELSE;
000177190328                                     IF IndLastDateC <> 0;
000178190328                                       CSTPHN = 'Date Problem';
000179190328                                       NextCallDate = D'9999-09-09';
000180190328                                       PHNLDC = D'9999-09-09';
000181190328                                       ENDIF;
000182190328                                    ENDIF;
000183190328
000184190328                                    SELECT;
000185190328                                      WHEN SQLSTATE = '00000';
000186190328                                       DUMMY = 0;
000187190328                                      WHEN SQLSTATE = '02000';
000188190328                                         CSTPHN = 'Not Found';
000189190328                                         NextCallDate =  D'9999-09-09';
000190190328                                         PHNLDC =  D'9999-09-09';
000191190328                                         PHNCOM = *ALL'*';
000192190328                                         CSTSLN = *ALL'*';
000193190328                                      WHEN %Subst (SQLSTATE :1 :2) = '01';
000194190328                                         NextCallDate =  D'9999-09-09';
000195190328                                         PHNLDC =  D'9999-09-09';
000196190328                                         PHNCOM = *ALL'*';
000197190328                                         CSTPHN = *ALL'*';
000198190328                                      OTHER;
000199190328                                       NextCallDate =  D'9999-09-09';
000200190328                                       PHNLDC =  D'9999-09-09';
000201190328                                        PHNCOM = *ALL'*';
000202190328                                       CSTSLN = *ALL'*';
000203190328                                        CSTPHN = *ALL'*';
000204190328                                    ENDSL;
000205190328                                     IF   PHNLDC = OLDESTDATE;
000206190328                                             FLAG = '<------';
000207190328                                     ELSE;
000208190328                                            FLAG = '';
000209190328                                    ENDIF;
000210190328
000211190328                        ENDSR ;
000212190328
000213190328        //**********************************************************************
000214190328        // S U M M A R Y I N F O   S U B R O U T I N E
000215190328        //**********************************************************************
000216190328                         BEGSR  SummaryInfo;
000217190328        //  D E T E R M I N E   T O T A L S   F O R   CONTACTW18 & CUSTOMER18
000218190328                                 EXEC SQL
000219190328                                  SELECT COUNT(*) INTO :ContactTotal
000220190404                                  FROM  BCI433LIB/CONTACTW19;
000221190328
000222190328
000223190328                                IF (SQLCODE <> 0) OR (SQLWN0 = 'W');
000224190328                                    ContactTotal = -99999;
000225190328                                 ENDIF;
000226190328
000227190328                                 EXEC SQL
000228190328                                  SELECT COUNT(*)
000229190328                                     INTO :CustomerTotal
000230190404                                    FROM BCI433LIB/CONTACTW19
000231190328                                    WHERE CstLastCAllDate IS NULL;
000232190328
000233190328
000234190328                                 IF (SQLCODE <> 0) OR (SQLWN0 = 'W');
000235190328                                   CustomerTotal  =-99999;
000236190328                                 ENDIF;
000237190328
000238190328        // D E T E R M I N E   N U M B E R   O F   U N K N O W N   L A S T   D A T E
000239190328       //  C A L L E D   R E C O R D S
000240190328                               EXEC SQL
000241190328                                  SELECT COUNT(*)
000242190328                                     INTO :UnknownTotal
000243190404                                    FROM BCI433LIB/CONTACTW19
000244190328                                    WHERE CstLastCAllDate IS NULL;
000245190328
000246190328
000247190328                                 IF (SQLCODE <> 0) OR (SQLWN0 = 'W');
000248190328                                   UnknownTotal  =-99999;
000249190328                                 ENDIF;
000250190328
000251190328        //  D E T E R M I N E   O L D E S T   &  M O S T   R E C E N T  L A S T
000252190328       //   C A L L B A C K   D A T E S
000253190328                              EXEC SQL
000254190328                                  SELECT MIN(PHNLDC) INTO :OldestDate
000255190404                                   FROM BCI433LIB/CONTACTW19;
000256190328
000257190328                                  IF (SQLCODE <> 0) OR (SQLWN0 = 'W')
000258190328                                     AND (SQLWN2 <> 'W');
000259190328                                    OldestDate = D'9999-09-09';
000260190328                                   ENDIF;
000261190328
000262190328                                EXEC SQL
000263190328                                  SELECT MAX(PHNLDC) INTO :MostRecentDate
000264190404                                    FROM BCI433LIB/CONTACTW19;
000265190328
000266190328                                  IF (SQLCODE <> 0) OR (SQLWN0 = 'W')
000267190328                                   AND (SQLWN2 <> 'W');
000268190328                                    MostRecentDate = D'9999-09-09';
000269190328                                  ENDIF;
000270190328
000271190328
000272190328
000273190328
000274190328       // D E T E R M I N E   T H E   U S E R,  S E R V E R,  &   T I M E S T A M P
000275190328                              EXEC SQL
000276190328                                 SELECT USER, CURRENT TIMESTAMP,CURRENT SERVER
000277190328                                   INTO :User, :Timestamp, :Server
000278190328                                   FROM SYSIBM/SYSDUMMY1;
000279190328              ENDSR;
000280190328
000281190328      /END-FREE
000282190328
000283190328     OQPRINT    E            HEADINGS       2 02
000284190328     O                                            5 'USER:'
000285190328     O                       USER                16
000286190328     O                                           28 'TIMESTAMP:'
000287190328     O                       TIMESTAMP           55
000288190328     O                                           64 'SERVER:'
000289190328     O                       SERVER              75
000290190328     O                                           87 'PAGE:'
000291190328     O                       PAGE                90
000292190328     O          E            HEADINGS       2
000293190328     O                                           54 'Phone Log Report'
000294190328     O                       UDATE         Y     89
000295190328     O          E            HEADINGS       1
000296190328     O                                            5 'Sales'
000297190328     O                                           15 'Customer'
000298190328     O                                           31 'Customer Name'
000299190328     O                                           59 'Telephone'
000300190328     O                                           75 'Last Call'
000301190328     O                                           88 'Oldest Call'
000302190328     O                                          101 'Next Call'
000303190328     O          E            HEADINGS       2
000304190328     O                                            3 'ID'
000305190328     O                                           13 'Number'
000306190328     O                                           73 'Date'
000307190328     O                                           85 'Date'
000308190328     O                                           98 'Date'
000309190328     O          E            DETAIL         1
000310190328     O                       CSTSLN               3
000311190328     O                       CSTNUM              13
000312190328     O                       CSTNAM              48
000313190328     O                       CSTPHN              64
000314190328     O                       PHNLDC              75
000315190328     O                       FLAG                86
000316190328     O                       NextCallDate       101
000317190328     O          E            TOTALS      2  2
000318190328     O                                           32 'Summary Information'
000319190328     O          E            TOTALS         1
000320190404     O                                           26 'CONTACTW19 Total Records:'
000321190328     O                       ContactTotal  1     34
000322190328     O          E            TOTALS         1
000323190404     O                                           26 'CUSTOMER19 Total Records:'
000324190328     O                       CustomerTotal 1     34
000325190328     O          E            TOTALS      1  1
000326190328     O                                           27 'Oldest Last Callback Date:'
000327190328     O                       OldestDate          42
000328190328     O          E            TOTALS         1
000329190328     O                                           27 'Most Recent Callback Date:'
000330190328     O                       MostRecentDate      42
000331190328     O          E            TOTALS      2  1
000332190328     O                                           22 'Total Records with an'
000333190328     O                                           47 'Unknown Last Date Called'
000334190404     O                                           62 'in CONTACTW19:'
000335190328     O                       UnknownTotal        70
000336190328
