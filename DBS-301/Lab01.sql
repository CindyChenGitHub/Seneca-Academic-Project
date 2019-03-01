/*----------------------SENECA COLLEGE---------------------
Student     : YC
Email       : ychen465@myseneca.ca
Date        : May 10, 2018
Class       : DBS301 - Database Design II and SQL Using Oracle
Description : Lab01
---------------------------------------------------------------*/

/*QUESTION 1
This lab doesn't have the first question*/
-------------------------------------------
/*QUESTION 2
1 Start by ENTERING the following and record the number of rows. Your answer 'might' be different base on the semester.*/

SELECT * FROM EMPLOYEES;   How many rows? 54
SELECT * FROM DEPARTMENTS;  How many rows? 8 
SELECT * FROM JOB_HISTORY;  How many rows? 10
-------------------------------------------

/*QUESTION 3 ~ QUESTION
These lab doesn't have the first question*/
-------------------------------------------

/*QUESTION 6
What command would show the structure of the LOCATIONS table.*/

DESCRIBE LOCATIONS

Output:
Name           Null     Type         
-------------- -------- ------------ 
LOCATION_ID       NOT NULL   NUMBER(4)    
STREET_ADDRESS               VARCHAR2(40) 
POSTAL_CODE                  VARCHAR2(12) 
CITY              NOT NULL   VARCHAR2(30) 
STATE_PROVINCE               VARCHAR2(25) 
COUNTRY_ID                   CHAR(2)
-------------------------------------------

/*QUESTION 7
Create a query to display the output shown below. NOTE: unless you are using a fixed font like Courier New the output will be a little wavy looking.

City#   City    Province with Country Code 
---------------------------------------------------------------------------------
1000  Roma    IN THE IT 
1100  Venice    IN THE IT 
1200  Tokyo    Tokyo Prefecture IN THE JP 
1300  Hiroshima   IN THE JP 
1400  Southlake                     Texas IN THE US 
1500  South San Francisco    California IN THE US
*/

SELECT LOCATION_ID "City#",
		CITY "City",
		STATE_PROVINCE || ' IN THE ' || Country_ID "Province with Country Code"
FROM LOCATIONS;
-------------------------------------------

/*QUESTION 8
Create a query to display unique (department codes and job titles) from the EMPLOYEES table.*/

SELECT DISTINCT DEPARTMENT_ID "Department Codes",
				JOB_ID "Job Titles"
FROM EMPLOYEES;

Output:
Department Codes Job Titles
---------------- ----------
             110 AC_ACCOUNT
              90 AD_VP     
              50 ST_CLERK  
              80 SA_REP    
              50 ST_MAN    
              80 SA_MAN    
             110 AC_MGR    
              90 AD_PRES   
              60 IT_PROG   
              20 MK_MAN    
                 SA_REP    
              10 AD_ASST   
              20 MK_REP    

 13 rows selected
===============================================
