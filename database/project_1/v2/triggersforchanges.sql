
use ITIProjectdb ;

-- triggers for updating total grade for exam

-- 1. Trigger BEFORE INSERT on ExamQuestions
DELIMITER $$
CREATE TRIGGER trg_UpdateExamTotalGrade_BeforeInsert
BEFORE INSERT ON ExamQuestions
FOR EACH ROW
BEGIN
    UPDATE Exams e
    SET e.totalGrade = (
        SELECT COALESCE(SUM(qb.grade),0)
        FROM ExamQuestions eq
        JOIN QuestionsBank qb ON eq.qId = qb.qId
        WHERE eq.examId = NEW.examId
    )
    WHERE e.examId = NEW.examId;
END $$
DELIMITER ;

-- 2. Trigger AFTER DELETE on ExamQuestions
DELIMITER $$
CREATE TRIGGER trg_UpdateExamTotalGrade_AfterDelete
AFTER DELETE ON ExamQuestions
FOR EACH ROW
BEGIN
    UPDATE Exams e
    SET e.totalGrade = (
        SELECT COALESCE(SUM(qb.grade),0)
        FROM ExamQuestions eq
        JOIN QuestionsBank qb ON eq.qId = qb.qId
        WHERE eq.examId = OLD.examId
    )
    WHERE e.examId = OLD.examId;
END $$
DELIMITER ;

-- 3. Trigger AFTER UPDATE on QuestionsBank (grade change)
DELIMITER $$
CREATE TRIGGER trg_UpdateExamTotalGrade_AfterQuestionUpdate
AFTER UPDATE ON QuestionsBank
FOR EACH ROW
BEGIN
    UPDATE Exams e
    JOIN (
        SELECT eq.examId, COALESCE(SUM(qb.grade),0) AS totalGrade
        FROM ExamQuestions eq
        JOIN QuestionsBank qb ON eq.qId = qb.qId
        WHERE eq.qId = NEW.qId
        GROUP BY eq.examId
    ) t ON e.examId = t.examId
    SET e.totalGrade = t.totalGrade;
END $$
DELIMITER ;



-- triggers for updating score for attemp for exam
-- update score after insert in answer
DELIMITER $$

CREATE TRIGGER trg_UpdateAttemptScore_AfterInsert
AFTER INSERT ON answers
FOR EACH ROW
BEGIN
    UPDATE attemp a
    SET a.score = (
        SELECT COALESCE(SUM(qb.grade), 0)
        FROM answers ans
        JOIN choises ch ON ans.choiceId = ch.choiceId
        JOIN QuestionsBank qb ON ch.qId = qb.qId
        WHERE ans.attemptId = NEW.attemptId
        AND ch.isCorrect = 1
    )
    WHERE a.attemptId = NEW.attemptId;
END$$

DELIMITER ;

-- update score after update in answer
DELIMITER $$

CREATE TRIGGER trg_UpdateAttemptScore_AfterUpdate
AFTER UPDATE ON answers
FOR EACH ROW
BEGIN
    UPDATE attemp a
    SET a.score = (
        SELECT COALESCE(SUM(qb.grade), 0)
        FROM answers ans
        JOIN choises ch ON ans.choiceId = ch.choiceId
        JOIN QuestionsBank qb ON ch.qId = qb.qId
        WHERE ans.attemptId = NEW.attemptId
        AND ch.isCorrect = 1
    )
    WHERE a.attemptId = NEW.attemptId;
END$$

DELIMITER ;



-- update score after delete in answer
DELIMITER $$

CREATE TRIGGER trg_UpdateAttemptScore_AfterDelete
AFTER DELETE ON answers
FOR EACH ROW
BEGIN
    UPDATE attemp a
    SET a.score = (
        SELECT COALESCE(SUM(qb.grade), 0)
        FROM answers ans
        JOIN choises ch ON ans.choiceId = ch.choiceId
        JOIN QuestionsBank qb ON ch.qId = qb.qId
        WHERE ans.attemptId = OLD.attemptId
        AND ch.isCorrect = 1
    )
    WHERE a.attemptId = OLD.attemptId;
END$$

DELIMITER ;



