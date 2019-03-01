/*----------------------SENECA COLLEGE---------------------
Student     : YC
Email       : ychen465@myseneca.ca
Date        : June 15, 2018
Class       : DBS301 - Database Design II and SQL Using Oracle
Description : Lab06
---------------------------------------------------------------*/

/*QUESTION 1
This lab doesn't have the first question*/
-------------------------------------------
/*QUESTION 2
Make sure you exist as an employee with a NULL salary and 0.2 commission_pct in department 90. Fill in the other fields as well
That requires an INSERT*/

Correct Answer:
INSERT INTO EMPLOYEES
  VALUES
    (777,'Amal','Khandelwal','AKHANDELWAL','123.123.1234',
       '31-DEC-99','IT_PROG',NULL,.2,102,90);
-------------------------------------------
/*QUESTION 3
Change the salary of the both employees with a last name of Matos and Whalen to be 2500.*/

UPDATE EMPLOYEES
SET SALARY = 2500
WHERE UPPER(LAST_NAME) IN( 'MATOS', 'WHALEN');
-------------------------------------------
/*QUESTION 4
YOU MUST USE SUBQUERIES for these questions.
(Must also minimize the number of tables when answering. Example don't use 10 tables when 3 will do)
Display the last names of all employees who are in the same department as the employee named who has a name called Abel.*/

SELECT LAST_NAME
FROM EMPLOYEES
WHERE DEPARTMENT_ID IN
                        (SELECT DEPARTMENT_ID
                        FROM EMPLOYEES
                        WHERE UPPER(LAST_NAME) = 'ABEL'
                        OR UPPER(FIRST_NAME) = 'ABEL');
-------------------------------------------
/*QUESTION 5
Display the last name then first name of the lowest paid employee(s)*/

SELECT LAST_NAME, FIRST_NAME
FROM EMPLOYEES
WHERE SALARY = 
              (SELECT MIN(SALARY)
              FROM EMPLOYEES);
-------------------------------------------
/*QUESTION 6
Display the city that the lowest paid employee(s) are located in.*/

Correct Answer:
SELECT DISTINCT CITY
  FROM LOCATIONS JOIN DEPARTMENTS USING (LOCATION_ID) JOIN
       EMPLOYEES USING (DEPARTMENT_ID)
  WHERE SALARY =
          (SELECT MIN(SALARY) FROM EMPLOYEES);
-------------------------------------------
/*QUESTION 7
Display the last name and  first name of the lowest paid employee(s) in each department*/

SELECT LAST_NAME, FIRST_NAME
FROM EMPLOYEES
WHERE (SALARY, DEPARTMENT_ID) IN
                                (SELECT MIN(SALARY), DEPARTMENT_ID
                                FROM EMPLOYEES
                                GROUP BY DEPARTMENT_ID);
-------------------------------------------
/*QUESTION 8
Display the last name of the lowest paid employee(s) in each city*/

Correct Answer:
SELECT LAST_NAME
  FROM EMPLOYEES
  WHERE SALARY IN
        (SELECT MIN(SALARY)
           FROM LOCATIONS
           JOIN DEPARTMENTS USING (LOCATION_ID)
           JOIN EMPLOYEES USING (DEPARTMENT_ID)
           GROUP BY CITY);
-------------------------------------------
/*QUESTION 9
Display last name and salary for all employees who earn less than the lowest salary in ANY department.
Sort the output by top salaries first and then by last name.*/

SELECT LAST_NAME, SALARY
FROM EMPLOYEES
WHERE SALARY < ANY
                  (SELECT MIN(SALARY)
                  FROM EMPLOYEES
                  GROUP BY DEPARTMENT_ID)
ORDER BY SALARY DESC, LAST_NAME;
-------------------------------------------
/*QUESTION 10
Display last name, job title and salary for all employees whose salary matches any of the salaries from the IT Department.
Do NOT use Join method.
Sort the output by salary ascending first and then by last_name*/

SELECT LAST_NAME, JOB_ID, SALARY
FROM EMPLOYEES
WHERE SALARY IN						
                    (SELECT SALARY
                    FROM EMPLOYEES
                    WHERE DEPARTMENT_ID = 
                                          (SELECT DEPARTMENT_ID
                                          FROM DEPARTMENTS
                                          WHERE DEPARTMENT_NAME = 'IT'))
ORDER BY SALARY ASC, LAST_NAME;
===========================================================================