/*----------------------SENECA COLLEGE---------------------
Student     : YC
Email       : ychen465@myseneca.ca
Date        : May 18, 2018
Class       : DBS301 - Database Design II and SQL Using Oracle
Description : Lab02
---------------------------------------------------------------*/

/*QUESTION 1
Display the (1) employee_id,(2) Last name, First name (as one name with a comma between) and a column name called Full Name (3) salary
Only show employees earning in the range of $8000 to $15,000. 
Sort the output by top salaries first and then by last name.
*/
SELECT
	  EMPLOYEE_ID AS "Employee_ID",
	  FIRST_NAME ||', '||LAST_NAME AS "Full Name",
	  TO_CHAR(SALARY, '$999,999.99') AS "Salary"
	FROM EMPLOYEES
	WHERE (SALARY BETWEEN 8000 AND 15000)
	ORDER BY SALARY DESC, LAST_NAME;

-------------------------------------------
/*QUESTION 2
Modify previous query (#1) so that additional condition is to display only 
if they work as Programmers or Sales Representatives. 
Use same sorting as before.*/

SELECT
	  EMPLOYEE_ID AS "Employee_ID",
	  FIRST_NAME ||', '||LAST_NAME AS "Full Name",
	  TO_CHAR(SALARY, '$999,999.99') AS "Salary",
	  JOB_ID AS "Job_ID"
	FROM EMPLOYEES
	WHERE (SALARY BETWEEN 8000 AND 15000)
	AND JOB_ID IN ('IT_PROG' , 'SA_REP')
	ORDER BY SALARY DESC, LAST_NAME;
-------------------------------------------
/*QUESTION 3
The Human Resources department wants to find high salary and low salary employees.
Use columns, employee id, last name, salary and job_id only.
You are modifying a previous query so that it displays the same job titles but 
for people who earn outside the given salary range from question.  Use same sorting as before.*/

SELECT
	  EMPLOYEE_ID AS "Employee_ID",
	  FIRST_NAME ||', '||LAST_NAME AS "Full Name",
	  TO_CHAR(SALARY, '$999,999.99') AS "Salary",
	  JOB_ID AS "Job_ID"
	FROM EMPLOYEES
	WHERE (SALARY NOT BETWEEN 8000 AND 15000)
	AND JOB_ID IN ('IT_PROG' , 'SA_REP')
	ORDER BY SALARY DESC, LAST_NAME;
-------------------------------------------
/*QUESTION 4
This question just code as the form that has been given*/
	
SELECT
    last_name AS "Last Name",
    salary AS "Salary",
    job_id AS "Job Title",
    hire_date as "Started"
    FROM employees
    WHERE
        (hire_date < DATE '1998-01-01')
    ORDER BY hire_date DESC;
-------------------------------------------
/*QUESTION 5
Display the job titles and full names of employees whose first name contains an ‘e’ or ‘E’  anywhere as well as a 'g'. The output should look like:
Job Title  Full Name                                    
---------- ----------------------------------------------
SA_REP     Miguel Sanchez
*/

SELECT
	  JOB_ID AS "Job Tittle",
	  FIRST_NAME||' '||LAST_NAME AS "Full Name"
	FROM EMPLOYEES
	WHERE (FIRST_NAME LIKE '%e%'
	OR FIRST_NAME LIKE '%E%')
	AND FIRST_NAME LIKE '%g%';		/*Note: use "AND", not "OR".*/
-------------------------------------------
/*QUESTION 6
Create a report to display last name, salary, and commission percent for all employees that earn a commission and employee number greater than 100.*/

SELECT
	  LAST_NAME as "Last Name",
	  SALARY as "Salary",
	  COMMISSION_PCT as "Commission Percent"
	FROM EMPLOYEES
	WHERE COMMISSION_PCT IS NOT NULL
	AND EMPLOYEE_ID > 100;
-------------------------------------------
/*QUESTION 7
	
Do the same as previous question, but use a numeric value instead of a column name to put the report in order by salary from highest to lowest*/

SELECT
	  LAST_NAME as "Last Name",
	  SALARY as "Salary",
	  COMMISSION_PCT as "Commission Percent"
	FROM EMPLOYEES
	WHERE COMMISSION_PCT IS NOT NULL
	AND EMPLOYEE_ID > 100
	ORDER BY 2 DESC;
===========================================================================