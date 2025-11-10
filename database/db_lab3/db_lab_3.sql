use iti;

create table if not exists Employees  (
	Fname varchar(50) not null,
	Lname varchar(50) not null, 
	SSN int primary key,
	BDATE date not null,
	Address varchar(255) not null,
    Sex varchar(1) not null,
	Salary float default 10000,
	Superssn  int null,
	Dno int,
    foreign key (Superssn) references Employees(SSN) on delete set null on update cascade
);

Create Table if not exists Departments (
	DNumber int primary Key,
	DName varchar(255) Not Null,
	MGRSSN int,
	MGRStart_date Date,
    foreign key (MGRSSN) references Employees(SSN) on delete set null on update cascade
);
    
create table if not exists Projects (
Pname varchar(50) not null,
	Pnumber	int primary key auto_increment,
    Plocation varchar(100) not null,
	City varchar(50) not null,
    Dnum int,
    foreign key (Dnum) references Departments(DNumber) on delete set null on update cascade
);

Create Table if not exists Works_for (
	ESSN int,
	Pno int not null,
	Hours int not null,
    foreign key (ESSN) references Employees(SSN) on delete cascade on update cascade,
    foreign key (Pno) references projects(Pnumber) on delete cascade on update cascade,
    primary key(ESSN, Pno)
);
    
create table if not exists Dependents(
	ESSN int,
	Dependent_name varchar(50) not null,
	Sex varchar(1) not null,
	Bdate date not null,
    foreign key (ESSN) references Employees(SSN) on delete CASCADE on update cascade,
    primary key (ESSn, Dependent_name)
);




-- task 1
insert into Employees (Fname, Lname, SSN, BDATE, Address, Sex, Salary, Superssn, Dno)
values ('Amir', 'Alsayed', 102672, '2002-05-05', 'Abu hammad', 'M', 11500, 112233, 30);

-- task 2
insert into Employees (Fname, Lname, SSN, BDATE, Address, Sex, Dno)
values ('Mohammed', 'Hamdey', 102660, '2002-07-01', '10th of rammadan', 'M', 30);

-- task 3
insert into Departments values (100, 'DEPT IT', 112233, '2006-11-1');

-- task 4
-- set mrs noha manager for dep 100
update Departments set MGRSSN = 968574 where DNumber = 100;
-- set me as manager for dep 20 in place of mrs noha
update Departments set MGRSSN = 102672  where DNumber = 20;
-- set me as sueprviseor for my frined.
update Employees set Superssn = 102672  where SSN = 102660;

-- task 5
-- but my frined in his place as supervisor
update Employees set Superssn = 102660  where Superssn = 223344;
update Departments set MGRSSN  = 102660  where MGRSSN = 223344;
delete from Employees where SSN = 223344;

-- task 6

update Employees set salary = salary  + salary * .2 where SSN = 102672;

-- 1
select * from Employees;

-- 2
select Fname,	Lname, Salary, Dno from Empoyees;

-- 3
select Pname, Plocation, Dnum from Departments;

-- 4
select concat(Fname, ' ', Lname) AS FullName, (Salary * 12 * 0.10) AS 'ANNUAL COMM'  from employees;

-- 5
select SSN, concat(Fname, ' ' Lname) as EmpName where salary > 1000;


-- 6
select SSN, concat(Fname, ' ' Lname) as EmpName where salary > 10000;

-- 7
select concat(Fname, ' ' Lname) as EmpName, salary  where sex = 'F';

-- 8
select DNumber , DName from Departments where MGRSSN = 968574;


-- 9
select Pnumber as ID, Pname as Names, Plocation as Location from Projects where Dnum = 10;



