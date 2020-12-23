LOAD CSV WITH HEADERS FROM 'file:///beremiz-csv-import/FB.csv' AS row
WITH toInteger(row.ID) AS FBId, row.name as FBName, toInteger(row.type) AS FBType,
	row.tagname AS FBTagname, row.icon AS FBIcon
MERGE (fb:FB {FBId: FBId})
	SET fb.name=FBName, fb.type=FBType, fb.tagname=FBTagname, fb.icon=FBIcon
RETURN count(fb)
CREATE CONSTRAINT ON (fb:FB) ASSERT fb.FBId IS UNIQUE
