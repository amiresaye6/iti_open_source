
use ITIProjectdb ;
-- ============================
-- Insert Departments
-- ============================
INSERT INTO Departments (detptId, name, headId) VALUES
(1, 'Computer Science', NULL),
(2, 'Electrical Engineering', NULL),
(3, 'Mechanical Engineering', NULL),
(4, 'Civil Engineering', NULL),
(5, 'Architecture', NULL);

-- ============================
-- Insert Professors
-- ============================
INSERT INTO Professors (pId, name, detptId) VALUES
(1, 'Dr. Ahmed Ali', 1),
(2, 'Dr. Sara Mohamed', 1),
(3, 'Dr. Hany Tarek', 2),
(4, 'Dr. Mona Khaled', 3),
(5, 'Dr. Omar Youssef', 4),
(6, 'Dr. Lina Samir', 5);

-- Update Department Heads
UPDATE Departments SET headId = 1 WHERE detptId = 1;
UPDATE Departments SET headId = 3 WHERE detptId = 2;
UPDATE Departments SET headId = 4 WHERE detptId = 3;
UPDATE Departments SET headId = 5 WHERE detptId = 4;
UPDATE Departments SET headId = 6 WHERE detptId = 5;

-- ============================
-- Insert Courses
-- ============================
INSERT INTO Courses (courseId, name, detptId) VALUES
(1, 'Database Systems', 1),
(2, 'Algorithms', 1),
(3, 'Operating Systems', 1),
(4, 'Digital Electronics', 2),
(5, 'Circuit Analysis', 2),
(6, 'Mechanics', 3),
(7, 'Thermodynamics', 3),
(8, 'Structural Analysis', 4),
(9, 'Concrete Design', 4),
(10, 'Architectural Design', 5);

-- ============================
-- Insert Students
-- ============================
INSERT INTO Students (sId, userName, name, password, faculty, degree, level) VALUES
(1, 'ahmeds', 'Ahmed Samir', 'pass123', 'Engineering', 'BSc', 3),
(2, 'saram', 'Sara Mohamed', 'pass123', 'Engineering', 'BSc', 3),
(3, 'hanyt', 'Hany Tarek', 'pass123', 'Engineering', 'BSc', 3),
(4, 'monak', 'Mona Khaled', 'pass123', 'Engineering', 'BSc', 4),
(5, 'omary', 'Omar Youssef', 'pass123', 'Engineering', 'BSc', 4),
(6, 'linas', 'Lina Samir', 'pass123', 'Architecture', 'BSc', 3);

-- ============================
-- Insert StudentCourses
-- ============================
INSERT INTO StudentCourses (sId, courseId) VALUES
(1,1),(1,2),(1,3),
(2,1),(2,4),(2,5),
(3,2),(3,3),(3,6),
(4,6),(4,7),
(5,8),(5,9),(5,10),
(6,1),(6,10);

-- ============================
-- Insert Exams
-- ============================
INSERT INTO Exams (examId, name, startTime, endTime, totalGrade, pId, courseId) VALUES
(1, 'DB Midterm', '2025-12-01 10:00:00', '2025-12-01 12:00:00', 0, 1, 1),
(2, 'DB Final', '2025-12-20 10:00:00', '2025-12-20 12:00:00', 0, 1, 1),
(3, 'Algorithms Midterm', '2025-12-02 10:00:00', '2025-12-02 12:00:00', 0, 2, 2),
(4, 'Operating Systems Midterm', '2025-12-03 10:00:00', '2025-12-03 12:00:00', 0, 2, 3);

-- ============================
-- Insert ExamQuestions
-- ============================
INSERT INTO ExamQuestions (qId, examId) VALUES
(1,1),(2,1),(3,2),(4,2),
(5,3),(6,3),(7,4),(8,4);

-- ============================
-- Insert QuestionsBank
-- ============================
INSERT INTO QuestionsBank (qId, questionText, grade, pId) VALUES
(1, 'What is a primary key?', 5, 1),
(2, 'Define normalization.', 5, 1),
(3, 'Explain joins.', 5, 1),
(4, 'SQL queries optimization?', 5, 1),
(5, 'What is Dijkstra algorithm?', 5, 2),
(6, 'Explain BFS and DFS.', 5, 2),
(7, 'OS process scheduling?', 5, 2),
(8, 'Explain memory management in OS.', 5, 2);

-- ============================
-- Insert Choises
-- ============================
INSERT INTO choises (choise, isCorrect, qId) VALUES
('A unique identifier for a record',1,1),
('A non-unique key',0,1),
('Organizing data into tables',0,1),
('Data redundancy reduction',1,2),
('Eliminate duplicate data',1,2),
('Any data',0,2),
('Pick shortest path',1,5),
('Pick any path',0,5),
('Visit nodes level by level',1,6),
('Visit nodes randomly',0,6),
('FIFO',1,7),
('LIFO',0,7),
('Paging and segmentation',1,8),
('Stack management',0,8),
('Stack management',0,3),
('Visit nodes randomly',1,3),
('Visit nodes randomly',1,4),
('Visit nodes randomly',0,4);


-- ============================
-- Insert Attempts
-- ============================
INSERT INTO attemp (attemptId, score, sId, examId) VALUES
(1,0,1,1),
(2,0,1,2),
(3,0,2,1),
(4,0,2,3),
(5,0,3,3),
(6,0,3,4),
(7,0,4,4);

-- ============================
-- Insert Answers
-- ============================
INSERT INTO answers (choiceId, attemptId) VALUES
(1,1),
(4,1),
(15,2),
(17,2),
(7,4),
(9,4),
(11,6),
(13,6);

-- ============================
-- Insert Teaches
-- ============================
INSERT INTO Teaches (degree, level, pId, courseId) VALUES
('BSc', 3, 1, 1),  -- Dr. Ahmed Ali teaches Database Systems
('BSc', 3, 2, 2),  -- Dr. Sara Mohamed teaches Algorithms
('BSc', 3, 2, 3),  -- Dr. Sara Mohamed teaches Operating Systems
('BSc', 3, 3, 4),  -- Dr. Hany Tarek teaches Digital Electronics
('BSc', 3, 3, 5),  -- Dr. Hany Tarek teaches Circuit Analysis
('BSc', 4, 4, 6),  -- Dr. Mona Khaled teaches Mechanics
('BSc', 4, 4, 7),  -- Dr. Mona Khaled teaches Thermodynamics
('BSc', 4, 5, 8),  -- Dr. Omar Youssef teaches Structural Analysis
('BSc', 4, 5, 9),  -- Dr. Omar Youssef teaches Concrete Design
('BSc', 3, 6, 10); -- Dr. Lina Samir teaches Architectural Design

-- ============================
-- Insert evaluateCourse
-- ============================
INSERT INTO evaluateCourse (rating, comment, sId, courseId) VALUES
(5, 'Very useful course', 1, 1),
(4, 'Challenging but good', 1, 2),
(5, 'Excellent explanations', 2, 1),
(3, 'Hard to follow', 2, 4),
(4, 'Good examples', 3, 2),
(5, 'Loved the assignments', 3, 3),
(4, 'Practical and theoretical', 4, 6),
(5, 'Well structured', 5, 8),
(4, 'Good content', 6, 10);

-- ============================
-- Insert evaluateProfessor
-- ============================
INSERT INTO evaluateProfessor (rating, comment, pId, sId, courseId) VALUES
(5, 'Excellent lecturer', 1, 1, 1),
(4, 'Very helpful', 2, 1, 2),
(5, 'Clear explanations', 2, 3, 3),
(3, 'Could be more engaging', 3, 2, 4),
(4, 'Good practical examples', 3, 3, 5),
(5, 'Fantastic teaching', 4, 4, 6),
(4, 'Great examples', 5, 5, 8),
(5, 'Excellent guidance', 6, 6, 10);




























-- first update total grades in exams 
SET SQL_SAFE_UPDATES = 0;
UPDATE Exams e
JOIN (
    SELECT eq.examId, COALESCE(SUM(qb.grade),0) AS totalGrade
    FROM ExamQuestions eq
    JOIN QuestionsBank qb ON eq.qId = qb.qId
    GROUP BY eq.examId
) t ON e.examId = t.examId
SET e.totalGrade = t.totalGrade;
