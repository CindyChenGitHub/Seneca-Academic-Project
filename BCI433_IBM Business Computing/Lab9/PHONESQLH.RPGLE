000100190313         // **************************************************************************
000200190313        //  CUSTOMER19 READ BY NATIVE LANGUAGE (ILE RPG)
000300190313        //  CONTACTW19 ROW RETRIEVED WITH EMBEDDED SQL
000400190313        //  DETAIL REPORT LINE INCLUDES INFORMATION FROM CUSTOMER19 AND CONTACTW19
000500190313        //  SUMMARRY REPORT INFORMATION RETRIEVED WITH EMBEDDED SQL STATEMENTS
000600190314
000700190313           DCL-F PHNREPORT PRINTER OFLIND(*IN01) ;
000800190313           DCL-F CUSTOMER19 DISK(*EXT) KEYED USAGE(*INPUT)
000900190314                 RENAME(CUSTOMER19:CUSTR);
001000190314                      // data structure for host variables from CONTACTW19
001100190314
001200190314                     // Standalone fields for indicator variables
001300190314
001400190314
001500190314
001600190314           DCL-S Dummy  Zoned(1);
001700190314
001800190314        //**************************************************************************
001900190314        //*                        ***   M A I N   R O U T I N E   ***
002000190314        //**************************************************************************
002100190314
002200070119                EXSR SummaryInfo;
002300190313                WRITE HEADINGS;
002400190313                READ CUSTOMER19;
002500070119                DOW NOT %EOF;
002600070119                    EXSR SQLSelect;
002700190313                    IF *IN01 = *ON;
002800190313                       Write HEADINGS;
002900190313                       *IN01 = *OFF;
003000070119                    ENDIF;
003100190313                    Write DETAIL;
003200190313                   READ CUSTOMER19;
003300070119                ENDDO;
003400190313                Write SUMMARY;
003500070119                *INLR = *ON;
003600070119                RETURN;
003700080923        //**********************************************************************
003800080923        //   S Q L S E L E C T   S U B R O U T I N E
003900080923   //   //********************************************************************
004000080923   //                  BEGSR    SQLSelect ;
004100080923   //    // A row from the contacts table that has the same customer number as t
004200190313   //    // read from the CUSTOMER19 file is retrieved to find out the last date
004300080923   //    // phone number, comments and the salesperson number.
004400080923   //
004500080923   //    //  The call back interval is added to the last date called to determin
004600080923   //    //  next date to call.  Since null values may be stored in the last dat
004700080923   //    // indicator variables are used.
004800190314
004900190314
005000190314
005100190314
005200190314
005300190314
005400190314
005500190314
005600190314
005700190314
005800190314
005900190314
006000190314
006100190314
006200190314
006300190314
006400190314
006500190314
006600190314
006700190314
006800190314
006900080923                         ENDSR ;
007000080923        //**********************************************************************
007100080923        // S U M M A R Y I N F O   S U B R O U T I N E
007200080923        //**********************************************************************
007300080923                         BEGSR  SummaryInfo;
007400190313        //  D E T E R M I N E   T O T A L S   F O R   CONTACTW19 & CUSTOMER19
007500190314
007600190314
007700190314
007800190314
007900190314
008000190314
008100190314
008200190314
008300190314
008400190314
008500190314
008600190314
008700190314
008800190314
008900190314
009000190314        // D E T E R M I N E   N U M B E R   O F   U N K N O W N   LAST   DATE CALLED
009100190314
009200190314
009300190314
009400190314
009500190314
009600190314
009700190314
009800190314
009900190314
010000190314
010100080923        //  D E T E R M I N E   O L D E S T   &  M O S T   R E C E N T  L A S T
010200080923
010300190314
010400190314
010500190314
010600190314
010700190314
010800190314
010900190314
011000190314
011100190314
011200190314
011300190314
011400190314
011500190314
011600190314
011700190314
011800190314
011900190314
012000190314
012100080923       // D E T E R M I N E   T H E   U S E R   S E R V E R   &   T I M E S T A
012200080923
012300190314
012400190314
012500190314
012600190314
012700190314
012800080923                         ENDSR;
