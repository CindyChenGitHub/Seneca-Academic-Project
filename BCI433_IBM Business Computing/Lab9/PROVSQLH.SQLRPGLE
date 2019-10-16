000100190328     F*********************************************************************************************
000101190328     F* THIS PROGRAM USES A CURSOR TO LOAD A TEMPORARY RESULT TABLE THAT JOINS THE ORDERS,        *
000102190328     F* ORDERLINE, CUSTOMER, PART AND SALESREP TABLES.  ORDER NUMBER IS USED AS A CONTROL BREAK   *
000103190328     F* FIELD WHERE CUSTOMER TOTALS ARE PRINTED ON NEW ORDER NUMBERS                              *
000104190328     F*                                                                                           *
000105190328     F*********************************************************************************************
000106190328
000107190328     FQPRINT    O    F  132        PRINTER OFLIND(*INOF) FORMOFL(60) FORMLEN(66)
000108190328     D* D A T A   S T R U C T U R E   FOR CUSTOMER RECORD
000109190328     D CustomerRecord  DS
000110190328     D CustId                         6
000111190328     D FullName                      31
000112190328     D City                          20
000113190328     D Purchase                       7  2
000114190328     D PDate                           D
000115190328     D Province                      10
000116190328     D ProvinceH       S             10
000117190328     D TotalCost       S              8  2
000118190328     D TotalRecords    S              5  0
000119190328     D TotalExtended   S              9  2
000120190328     D OntarioTot      S              3  0
000121190328     D QuebecTot       S              3  0
000122190328     D ManitobaTot     S              3  0
000123190328     D EndOfFile       S               N
000124190328     C/EJECT
000125190328     C********************************************************************************************
000126190328     C*                        ***   M A I N   R O U T I N E   ***                               *
000127190328     C********************************************************************************************
000128190328      /FREE
000129190328                EXSR PrepareFiles;
000130190328                EXCEPT HEADINGS;
000131190328                EXSR GetRow;
000132190328                Except NewProv;
000133190328                ProvinceH = Province;
000134190328                DOW NOT EndOfFile;
000135190328                    IF *INOF = *ON;
000136190328                        EXCEPT HEADINGS;
000137190328                       *INOF = *OFF;
000138190328                    ENDIF;
000139190328                    If ProvinceH = Province;
000140190328                       Except Detail;
000141190328                    Else;
000142190328                       ProvinceH = Province;
000143190328                       Except NewProv;
000144190328                       Except Detail;
000145190328                    EndIf;
000146190328                    TotalCost     = TotalCost     + Purchase;
000147190328                    TotalRecords= TotalRecords + 1;
000148190328                    EXSR GetRow;
000149190328                ENDDO;
000150190328                EXSR   WRAPUP;
000151190328                EXCEPT Totals;
000152190328                *INLR = *ON;
000153190328                RETURN;
000154190328        //************************************************************************************
000155190328        // O P E N F I L E S   S U B R O U T I N E
000156190328        //*****************************************************************************************
000157190328         BEGSR  PrepareFiles;
000158190328        // S E T   U P   T H E   T E M P O R A R Y   R E S U L T  S T R U C T U R E
000159190328            EXEC SQL
000160190328               DECLARE ALLPROVCURSOR CURSOR
000161190328                  FOR
000162190328                  SELECT CUSTID, TRIM(FNAME) || ' ' || TRIM(LNAME), CITY,
000163190328                         PURCHASE,
000164190328                        PDATE, 'Ontario' AS PROVINCE
000165190328                  FROM BCI433LIB/ONTARIO
000166190328                  WHERE PURCHASE > 150
000167190328                  UNION ALL
000168190328                   SELECT CUSTID, TRIM(FNAME) || ' ' || TRIM(LNAME), CITY,
000169190328                           PURCHASE,
000170190328                        PDATE, 'Quebec' AS PROVINCE
000171190328                  FROM BCI433LIB/QUEBEC
000172190328                 WHERE PURCHASE > 150
000173190328                  UNION ALL
000174190328                   SELECT CUSTID, TRIM(FNAME) || ' ' || TRIM(LNAME), CITY,
000175190328                         PURCHASE,
000176190328                         PDATE, 'Manitoba' AS PROVINCE
000177190328                 FROM BCI433LIB/MANITOBA
000178190328                  WHERE PURCHASE > 150
000179190328                     FOR READ ONLY;
000180190328
000181190328
000182190328        // A   T E M P O R A R Y   R E S U L T   T A B L E   I S   C R E A T E D
000183190328           EXEC SQL
000184190328               OPEN ALLPROVCURSOR;
000185190328              IF SQLCODE <> 0 OR SQLWN0 = 'W';
000186190328                EndOfFile = *ON;
000187190328             ENDIF;
000188190328
000189190328
000190190328            ENDSR;
000191190328        //****************************************************************************************
000192190328        //   G E T     R O W    S U B R O U T I N E
000193190328        //*****************************************************************************************
000194190328            BEGSR     GETROW;
000195190328             EXEC SQL
000196190328                   FETCH NEXT
000197190328                       FROM ALLPROVCURSOR
000198190328                       INTO :CustomerRecord;
000199190328                  IF SQLCODE <> 0 OR SQLWN0 = 'W';
000200190328                    EndOfFile = *ON;
000201190328                  ENDIF;
000202190328
000203190328             ENDSR;
000204190328        //*****************************************************************************************
000205190328        // W R A P U P     S U B R O U T I N E
000206190328        //*****************************************************************************************
000207190328           BEGSR WRAPUP;
000208190328           EXEC SQL
000209190328                   CLOSE ALLPROVCURSOR;
000210190328
000211190328                IF SQLCODE <> 0 OR SQLWN0 = 'W';
000212190328                   EndOfFile = *ON;
000213190328                ENDIF;
000214190328
000215190328             EXEC SQL
000216190328               SELECT COUNT(*) INTO :OntarioTot
000217190328                  FROM BCI433LIB/ONTARIO
000218190328                  WHERE PURCHASE <= 150;
000219190328
000220190328             IF SQLCODE <> 0 OR SQLWN0 = 'W';
000221190328               OntarioTot = -999;
000222190328              ENDIF;
000223190328
000224190328              EXEC SQL
000225190328               SELECT COUNT(*) INTO :QuebecTot
000226190328                  FROM BCI433LIB/QUEBEC
000227190328                  WHERE PURCHASE <= 150;
000228190328
000229190328              IF SQLCODE <> 0 OR SQLWN0 = 'W';
000230190328                QuebecTot = -999;
000231190328              ENDIF;
000232190328
000233190328
000234190328              EXEC SQL
000235190328                SELECT COUNT(*) INTO :ManitobaTot
000236190328                FROM BCI433LIB/MANITOBA
000237190328                  WHERE PURCHASE <= 150;
000238190328
000239190328             IF SQLCODE <> 0 OR SQLWN0 = 'W';
000240190328                ManitobaTot = -999;
000241190328              ENDIF;
000242190328
000243190328          ENDSR;
000244190328      /END-FREE
000245190328     OQPRINT    E            HEADINGS       2 02
000246190328     O                                           67 'Customers > $150.00'
000247190328     O                                          110 'Page:'
000248190328     O                       PAGE               115
000249190328     O          E            HEADINGS       1
000250190328     O                                            8 'Province'
000251190328     O                                           23 'Customer ID'
000252190328     O                                           42 'Full Name'
000253190328     O                                           64 'City'
000254190328     O                                           90 'Purchase'
000255190328     O                                          101 'Purchase'
000256190328     O          E            HEADINGS       2
000257190328     O                                           89 'Amount'
000258190328     O                                           99 'Date'
000259190328     o          E            NewProv        1
000260190328     O                       Province            10
000261190328     o          E            DETAIL         1
000262190328     O                       CustID              20
000263190328     O                       FullName            61
000264190328     O                       City                74
000265190328     O                       Purchase      1     90
000266190328     O                       PDate              103
000267190328     O          E            Totals      2  1
000268190328     O                                           79 'Total Amount:'
000269190328     O                       TotalCost     1     90
000270190328     O          E            Totals      1  1
000271190328     O                                           17 'Total Customers:'
000272190328     O                       TotalRecords  1     24
000273190328     O          E            TOTALS         2 02
000274190328     O                                           67 'Customers <= $150.00'
000275190328     O                                          110 'Page:'
000276190328     O                       PAGE               115
000277190328     O          E            Totals         2
000278190328     O                                           18 'Ontario'
000279190328     O                                           41 'Quebec'
000280190328     O                                           69 'Manitoba'
000281190328     O          E            Totals         1
000282190328     O                       OntarioTot    1     15
000283190328     O                       QuebecTot     1     38
000284190328     O                       ManitobaTot   1     66
000285190328
