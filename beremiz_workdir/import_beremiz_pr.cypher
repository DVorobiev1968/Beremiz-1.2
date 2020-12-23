LOAD CSV WITH HEADERS FROM 'file:///beremiz-csv-import/PR.csv' AS row
WITH toInteger(row.ID) AS programId, row.name as programName, toInteger(row.type) AS programType,
	row.tagname AS programTagname, row.icon AS programIcon
MERGE (p:Program {programId: programId})
	SET p.name=programName, p.type=programType, p.tagname=programTagname, p.icon=programIcon
RETURN count(p)
CREATE CONSTRAINT ON (p:Program) ASSERT p.programId IS UNIQUE;
