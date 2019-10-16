000100190321     FSALESTRANSIF   E             DISK    RENAME(SALESTRANS:SALESTRANR)
000200190321     FSALESSTAFFUF A E           K DISK
000300190321     FQPRINT    O    F  132        PRINTER OFLIND(*INOF)
000301190321     D SALESTRANSDS    DS
000400190321     D   TDEPT
000402190321     D   TSALESID
000403190321     D   TFNAME
000404190321     D   TLNAME
000405190321     D   TCITY
000406190321     D   TADDRESS
000407190321     D   TPCODE
000408190321     D SALESSTAF2DS    DS
000409190321     D    DEPT
000410190321     D    SALESID
000411190321     D    FNAME
000412190321     D    LNAME
000413190321     D    CITY
000414190321     D    ADDRESS
000415190321     D    PCODE
000416190321     D FullKey         DS                  LikeRec(SALESTFR: *Key)
000417190321     C/FREE
003000190321      WRITE   HEADING;
003100190321      READ SALESTRANS;
003200190321      DOW NOT %EOF;
003300190321                      Fullkey = Tept + TSalesID;
003400190321                      CHAIN %KDS(Fullkey) SALESSTAF2;
003500101110                      SELECT;
003600101110                        WHEN      %FOUND(SALESSTAF2);
003700101110                        SELECT;
003800101110                           WHEN      TCODE = 'C';
003900101110                              EXSR      CHGREC;
004000101110                           WHEN      TCODE = 'D';
004100101110                              EXSR      DELREC;
004200101110                           OTHER;
004300101110                              EXSR      ERROR;
004400101110                        ENDSL;
004500101110                        WHEN      NOT %FOUND(SALESSTAF2);
004600101110                           IF        TCODE = 'A';
004700101110                              EXSR      ADDREC;
004800101110                           ELSE;
004900101110                              EXSR      ERROR;
005000101110                           ENDIF;
005100101110                        WHEN      %ERROR;
005200101110                              EXSR      ERROR;
005300101110                        ENDSL;
005400190304                        IF *IN01 = *ON;
005500190304                          WRITE HEADING;
005600190304                          *IN01 = *OFF;
005700190304                        ENDIF;
005800190304                        WRITE    DETAIL;
005900171124                        READ      SALESTRANS;
006000101110                   ENDDO;
006100101110                   *INLR = *ON;
006200101110                   RETURN;
006300101110         BEGSR  ADDREC;
006400190321               SALESSTAF2DS = SALESTRANSDS;
006500190321               Phone = %Dec(TPhone:10:0);
006600190321               WRITE SALESTFR;
006700101110         ENDSR;
006800101110         BEGSR  CHGREC;
006900190321               SALESSTAF2DS = SALESTRANSDS;
007000190321               Phone        = %Dec(TPhone:10:0);
007100190321               UPDATE SALESTFR;
007200101110         ENDSR;
007300101110         BEGSR  DELREC;
007400101110                   DELETE    SALESTFR;
007500101110         ENDSR;
007600101110         BEGSR  ERROR;
007700101110                   TFNAME = 'UPDATE/DELETE/CHANGE';
007800101110                   TLNAME = 'E R R O R';
007900101110         ENDSR;
007901190321       /END-FREE
