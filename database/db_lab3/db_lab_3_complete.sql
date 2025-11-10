-- insert departments
INSERT INTO Departments (DNumber, DName, MGRSSN, MGRStart_date) VALUES
(10, 'DP1', NULL, '2005-01-01'),
(20, 'DP2', NULL, '2006-03-01'),
(30, 'DP3', NULL, '2006-06-01');



-- insert projects
INSERT INTO Projects (Pname, Pnumber, Plocation, City, Dnum) VALUES
('AL Solimaniah', 100, 'Cairo_Alex Road', 'Alex', 10),
('Al Rabwah', 200, '6th of October City', 'Giza', 10),
('Al Rawdah', 300, 'Zaied City', 'Giza', 10),
('Al Rowad', 400, 'Cairo_Faiyom Road', 'Giza', 20),
('Al Rehab', 500, 'Nasr City', 'Cairo', 30),
('Pitcho american', 600, 'Maady', 'Cairo', 30),
('Ebad El Rahman', 700, 'Ring Road', 'Cairo', 20);


-- insert employees
INSERT INTO Employees (Fname, Lname, SSN, BDATE, Address, Sex, Salary, Superssn, Dno) VALUES
('Amr', 'Omran', 321654, '1963-09-14', '44 Hilopolis.Cairo', 'M', 2500, NULL, NULL),
('Kamel', 'Mohamed', 223344, '1970-10-15', '38 Mohy el dien abo el Ezz St.Cairo', 'M', 1800, 321654, 10),
('Ahmed', 'Ali', 112233, '1965-01-01', '15 Ali fahmy St.Giza', 'M', 1300, 223344, 10),
('Hanaa', 'Sobhy', 123456, '1973-03-18', '38 Abdel Khalik Tharwat St. Downtown.Cairo', 'F', 800, 223344, 10),
('Noha', 'Mohamed', 968574, '1975-02-01', '55 Orabi St. El Mohandiseen .Cairo', 'F', 1600, 321654, 20),
('Edward', 'Hanna', 512463, '1972-08-19', '18 Abaas El 3akaad St. Nasr City.Cairo', 'M', 1500, 321654, 30),
('Mariam', 'Adel', 669955, '1982-06-12', '269 El-Haram st. Giza', 'F', 750, 512463, 20),
('Maged', 'Raoof', 521634, '1980-04-06', '18 Kholosi st.Shobra.Cairo', 'M', 1000, 968574, 30);

-- add ssn to deps
UPDATE Departments SET MGRSSN = 223344 WHERE DNumber = 10;
UPDATE Departments SET MGRSSN = 968574 WHERE DNumber = 20;
UPDATE Departments SET MGRSSN = 512463 WHERE DNumber = 30;


-- insert dependiants
INSERT INTO Dependents (ESSN, Dependent_name, Sex, Bdate) VALUES
(112233, 'Hala Saied Ali', 'F', '1970-10-18'),
(223344, 'Ahmed Kamel Shawki', 'M', '1998-03-27'),
(223344, 'Mona Adel Mohamed', 'F', '1975-04-25'),
(321654, 'Ramy Amr Omran', 'M', '1990-01-26'),
(321654, 'Omar Amr Omran', 'M', '1993-03-30'),
(321654, 'Sanaa Gawish', 'F', '1973-05-16'),
(512463, 'Sara Edward', 'F', '2001-09-15'),
(512463, 'Nora Ghaly', 'F', '1976-06-22');


-- insert works_for 
INSERT INTO Works_for (ESSN, Pno, Hours) VALUES
(223344, 100, 10),
(223344, 200, 10),
(223344, 300, 10),
(112233, 100, 40),
(968574, 400, 15),
(968574, 700, 15),
(968574, 300, 10),
(669955, 400, 20),
(223344, 500, 10),
(669955, 700, 7),
(669955, 300, 10),
(512463, 500, 10),
(512463, 600, 25),
(521634, 500, 10),
(521634, 600, 20),
(521634, 300, 6),
(521634, 400, 4);
