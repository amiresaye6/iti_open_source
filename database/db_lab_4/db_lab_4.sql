-- db lab 4
use iti;

-- task 1
select DNumber as department_id, DName, SSN as manager_id, concat(Fname, " ", Lname)
from departments join employees on departments.MGRSSN = employees.SSN;

-- task 2
select DName, pname from departments join projects on departments.DNumber = projects.Dnum;

-- task 3
select dependents.Dependent_name, dependents.Sex, dependents.Bdate, concat(Fname, " ", Lname ) as employeeName 
from dependents join employees on dependents.ESSN = employees.SSN;

-- task 4
-- a

SELECT D.Dependent_name AS Name, D.Sex as Gender
FROM dependents D
WHERE D.Sex = 'F'

UNION

SELECT D.Dependent_name AS Name, D.Sex as Gender
FROM dependents D
JOIN employees E ON D.ESSN = E.SSN
WHERE E.Sex = 'F';



-- b
SELECT D.Dependent_name AS Name, D.Sex AS Gender
FROM Dependents D
WHERE D.Sex = 'M'

UNION

SELECT D.Dependent_name AS Name, D.Sex AS Gender
FROM Dependents D
JOIN Employees E ON D.ESSN = E.SSN
WHERE D.Sex = 'M' AND E.Sex = 'M';


-- task 5
select Pnumber as Id, Pname as Name, Plocation as Location from projects where city = "Cairo" or city = "Alex";

-- task 6
select * from projects where Pname like "a%";

-- task 7
select * from employees where Dno = 30 and salary between 1000 and 2000;

-- task 8
select concat(Fname, " ", Lname) as name
 from employees e
 join works_for w
 on e.SSN = w.ESSN
 join projects p
 on p.PNumber = w.Pno
 where Dno = 10 
 and PName = "AL Rabwah"
 AND w.Hours >= 10;
 
 -- task 9
 select concat(e.Fname, " ", e.Lname) as name
 from employees e
 join employees s
 on e.Superssn = s.SSN
	WHERE s.Fname = 'Kamel' 
	AND s.Lname = 'Mohamed';
 
-- task 10
select Pname , sum(Hours) 
from projects p
 join works_for w
 on p.Pnumber = w.Pno
 group by Pname;
 
 -- task 11
 select concat(e.Fname, " ", e.Lname) as EmpName, p.Pname as projectName 
 from employees e 
 join works_for w 
 on e.SSN = w.ESSN 
 join projects p 
 on p.Pnumber = w.Pno
 order by p.Pname;
 
 -- task 12
 select * from departments where DNumber = 
 (select Dno from employees order by SSN limit 1); -- join --
 
 -- task 13
 select DName, min(salary) as minSalary, max(salary) as maxSalary, avg(salary) as avgSalary 
 from employees e join departments d on e.Dno = d.DNumber
 group by DName;
 
 -- task 14
 select Fname from employees e 
 left join dependents d 
 on e.SSN = d.ESSN
 where d.ESSN is null;
 
 
-- task 15
 
 select d.DNumber, d.DName, count(*) as empCount 
 from employees e 
 join departments d 
 on e.Dno = d.DNumber 
 group by d.DNumber
 having avg(salary) <= (select avg(salary) from employees)
 ;

-- task 16
select 
    e.SSN,
    CONCAT(e.Fname, ' ', e.Lname) as EmpName,
    e.Dno as DepNumber,
    p.Pname as ProjName,
    p.Pnumber as ProjNumber
from Employees e
join Works_for w on e.SSN = w.ESSN 
join Projects p on w.Pno = p.Pnumber
order by e.Dno, e.Lname, e.Fname;

 
 -- task 17
 select 
 p.Pname, d.DName, e.Lname
 from
 projects p 
 join departments d 
 on p.Dnum = d.DNumber
 join employees e
 on d.MGRSSN = e.SSN
 where p.City = "Cairo";
 ;
 