000100190328     F**************************************************************************
000101190328     F*  CUSTOMER18 READ BY NATIVE LANGUAGE (ILE RPG)
000102190328     F*  CONTACTF18 ROW RETRIEVED WITH EMBEDDED SQL
000103190328     F*  DETAIL REPORT LINE INCLUDES INFORMATION FROM CUSTOMER18 AND CONTACTW18
000104190328     F*  SUMMARY REPORT INFORMATION RETRIEVED WITH EMBEDDED SQL STATEMENTS
000105190328     F**************************************************************************
000106190328
000107190328     FCUSTOMER18IF   E             DISK    RENAME(CUSTOMER18:CUSTOMERRF)
000108190328     FQPRINT    O    F  132        PRINTER OFLIND(*INOF) FORMOFL(30) FORMLEN(66)
000109190328     D CONTACTF18    E DS
000110190328     D ContactTotal    S              5  0
000111190328     D CustomerTotal   S              5  0
000112190328     D UnknownTotal    S              5  0
000113190328     D OldestDate      S               D
000114190328     D MostRecentDate  S               D
000115190328     D User            S             10
000116190328     D Server          S             10
000117190328     D TimeStamp       S               Z
000118190328     D DateIn          S              5  0
000119190328     D IndLastDateC    S              4B 0
000120190328     D IndNextDateC    S              4B 0
000121190328
000122190328     D Dummy           S              1  0
000123190328     D Flag            S              7
000124190328     D NextCallDate    S               D
000125190328     C/EJECT
000126190328     C**************************************************************************
000127190328     C*                        ***   M A I N   R O U T I N E   ***
000128190328     C**************************************************************************
000129190328      /FREE
000130190328               EXSR SummaryInfo;
000131190328                EXCEPT HEADINGS;
000132190328               READ CUSTOMER18;
000133190328                DOW NOT %EOF;
000134190328                   EXSR SQLSelect;
000135190328                   IF *INOF = *ON;
000136190328                       EXCEPT HEADINGS;
000137190328                       *INOF = *OFF;
000138190328                    ENDIF;
000139190328                    EXCEPT DETAIL;
000140190328                   READ CUSTOMER18;
000141190328                ENDDO;
000142190328                EXCEPT TOTALS;
000143190328                *INLR = *ON;
000144190328                RETURN;
000145190328        //*************************************************************************
000146190328        //   S Q L S E L E C T   S U B R O U T I N E
000147190328        //********************************************************************
000148190328
000149190328        // A row from the contacts table that has the same customer number found in the
000150190328        // record read from the CUSTOMER17 file. That row is retrieved to find out the last
000151190328        // date called, phone number, comments and the salesperson number.
000152190328
000153190328        //  The call back interval is added to the last date called to determine the
000154190328        //  next date to call.  Since null values may be stored in the last date called
000155190328        // indicator variables are used.
000156190328                     BEGSR    SQLSelect ;
000157190328                                EXEC SQL
000158190328                                     SELECT PHNLDC + PHNCIT DAYS, PHNLDC,
000159190328                                       CSTPHN, PHNCOM, CSTSLN
000160190328                                    INTO :NextCallDate  :IndNextDateC,
000161190328                                          :CSTPHN, :PHNCOM, :CSTSLN
000162190328                                     FROM BCI433LIB/CONTATCF18
000163190328                                    WHERE CSTNUM = :CSTNUM;
000164190328
000165190328                                    IF IndLastDateC = -1;
000166190328                                     CSTPHN = 'UNKNOWN DATE';
000167190328                                     NextCallDate = D'9999-09-09';
000168190328                                     PHNLDC = D'9999-09-09';
000169190328
000170190328                                   ELSE;
000171190328                                     IF IndLastDateC <> 0;
000172190328                                       CSTPHN = 'Date Problem';
000173190328                                       NextCallDate = D'9999-09-09';
000174190328                                       PHNLDC = D'9999-09-09';
000175190328                                       ENDIF;
000176190328                                    ENDIF;
000177190328
000178190328                                    SELECT;
000179190328                                      WHEN SQLSTATE = '00000';
000180190328                                       DUMMY = 0;
000181190328                                      WHEN SQLSTATE = '02000';
000182190328                                         CSTPHN = 'Not Found';
000183190328                                         NextCallDate =  D'9999-09-09';
000184190328                                         PHNLDC =  D'9999-09-09';
000185190328                                         PHNCOM = *ALL'*';
000186190328                                         CSTSLN = *ALL'*';
000187190328                                      WHEN %Subst (SQLSTATE :1 :2) = '01';
000188190328                                         NextCallDate =  D'9999-09-09';
000189190328                                         PHNLDC =  D'9999-09-09';
000190190328                                         PHNCOM = *ALL'*';
000191190328                                         CSTPHN = *ALL'*';
000192190328                                      OTHER;
000193190328                                       NextCallDate =  D'9999-09-09';
000194190328                                       PHNLDC =  D'9999-09-09';
000195190328                                        PHNCOM = *ALL'*';
000196190328                                       CSTSLN = *ALL'*';
000197190328                                        CSTPHN = *ALL'*';
000198190328                                    ENDSL;
000199190328                                     IF   PHNLDC = OLDESTDATE;
000200190328                                             FLAG = '<------';
000201190328                                     ELSE;
000202190328                                            FLAG = '';
000203190328                                    ENDIF;
000204190328
000205190328
000206190328
000207190328                        ENDSR ;
000208190328        //**********************************************************************
000209190328        // S U M M A R Y I N F O   S U B R O U T I N E
000210190328        //**********************************************************************
000211190328                        BEGSR  SummaryInfo;
000212190328       //  D E T E R M I N E   T O T A L S   F O R   CONTACTW18 & CUSTOMER18
000213190328                                EXEC SQL
000214190328                                  SELECT COUNT(*) INTO :ContactTotal
000215190328                                  FROM  BCI433LIB/CONTACTF18;
000216190328
000217190328                                  IF (SQLCODE <> 0) OR (SQLWN0 = 'W');
000218190328                                    ContactTotal = -99999;
000219190328                                 ENDIF;
000220190328
000221190328                                 EXEC SQL
000222190328                                  SELECT COUNT(*)
000223190328                                     INTO :CustomerTotal
000224190328                                    FROM BCI433LIB/CUSTOMER18
000225190328                                    WHERE CstLastCAllDate IS NULL;
000226190328
000227190328
000228190328                                 IF (SQLCODE <> 0) OR (SQLWN0 = 'W');
000229190328                                   CustomerTotal  =-99999;
000230190328                                 ENDIF;
000231190328       // D E T E R M I N E   N U M B E R   O F   U N K N O W N   L A S T   D A T E
000232190328       //  C A L L E D   R E C O R D S
000233190328                                EXEC SQL
000234190328                                  SELECT COUNT(*)
000235190328                                     INTO :UnknownTotal
000236190328                                    FROM BCI433LIB/CUSTOMER18
000237190328                                    WHERE CstLastCAllDate IS NULL;
000238190328
000239190328
000240190328                                 IF (SQLCODE <> 0) OR (SQLWN0 = 'W');
000241190328                                   UnknownTotal  =-99999;
000242190328                                 ENDIF;
000243190328
000244190328
000245190328
000246190328
000247190328
000248190328       //  D E T E R M I N E   O L D E S T   &  M O S T   R E C E N T  L A S T
000249190328      //   C A L L B A C K   D A T E S
000250190328                                EXEC SQL
000251190328                                  SELECT MIN(PHNLDC) INTO :OldestDate
000252190328                                   FROM BCI433LIB/CONTACTW18;
000253190328
000254190328                                  IF (SQLCODE <> 0) OR (SQLWN0 = 'W')
000255190328                                     AND (SQLWN2 <> 'W');
000256190328                                    OldestDate = D'9999-09-09';
000257190328                                   ENDIF;
000258190328
000259190328                                EXEC SQL
000260190328                                  SELECT MAX(PHNLDC) INTO :MostRecentDate
000261190328                                    FROM BCI433LIB/CONTACTW18;
000262190328
000263190328                                  IF (SQLCODE <> 0) OR (SQLWN0 = 'W')
000264190328                                   AND (SQLWN2 <> 'W');
000265190328                                    MostRecentDate = D'9999-09-09';
000266190328                                  ENDIF;
000267190328     // D E T E R M I N E   T H E   U S E R,  S E R V E R,  &   T I M E S T A M P
000268190328                               EXEC SQL
000269190328                                 SELECT USER, CURRENT TIMESTAMP,CURRENT SERVER
000270190328                                   INTO :User, :Timestamp, :Server
000271190328                                   FROM SYSIBM/SYSDUMMY1;
000272190328              ENDSR;
000273190328
000274190328      /END-FREE
000275190328     OQPRINT    E            HEADINGS       2 02
000276190328     O                                            5 'USER:'
000277190328     O                       USER                16
000278190328     O                                           28 'TIMESTAMP:'
000279190328     O                       TIMESTAMP           55
000280190328     O                                           64 'SERVER:'
000281190328     O                       SERVER              75
000282190328     O                                           87 'PAGE:'
000283190328     O                       PAGE                90
000284190328     O          E            HEADINGS       2
000285190328     O                                           54 'Phone Log Report'
000286190328     O                       UDATE         Y     89
000287190328     O          E            HEADINGS       1
000288190328     O                                            5 'Sales'
000289190328     O                                           15 'Customer'
000290190328     O                                           31 'Customer Name'
000291190328     O                                           59 'Telephone'
000292190328     O                                           75 'Last Call'
000293190328     O                                           88 'Oldest Call'
000294190328     O                                          101 'Next Call'
000295190328     O          E            HEADINGS       2
000296190328     O                                            3 'ID'
000297190328     O                                           13 'Number'
000298190328     O                                           73 'Date'
000299190328     O                                           85 'Date'
000300190328     O                                           98 'Date'
000301190328     O          E            DETAIL         1
000302190328     O                       CSTSLN               3
000303190328     O                       CSTNUM              13
000304190328     O                       CSTNAM              48
000305190328     O                       CSTPHN              64
000306190328     O                       PHNLDC              75
000307190328     O                       FLAG                86
000308190328     O                       NextCallDate       101
000309190328     O          E            TOTALS      2  2
000310190328     O                                           32 'Summary Information'
000311190328     O          E            TOTALS         1
000312190328     O                                           26 'CONTACTW18 Total Records:'
000313190328     O                       ContactTotal  1     34
000314190328     O          E            TOTALS         1
000315190328     O                                           26 'CUSTOMER18 Total Records:'
000316190328     O                       CustomerTotal 1     34
000317190328     O          E            TOTALS      1  1
000318190328     O                                           27 'Oldest Last Callback Date:'
000319190328     O                       OldestDate          42
000320190328     O          E            TOTALS         1
000321190328     O                                           27 'Most Recent Callback Date:'
000322190328     O                       MostRecentDate      42
000323190328     O          E            TOTALS      2  1
000324190328     O                                           22 'Total Records with an'
000325190328     O                                           47 'Unknown Last Date Called'
000326190328     O                                           62 'in CONTACTW18:'
000327190328     O                       UnknownTotal        70
000328190328
