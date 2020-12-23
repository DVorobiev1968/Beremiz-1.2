LOAD CSV WITH HEADERS FROM 'file:///beremiz-csv-import/PR-FB.csv' AS row
WITH toInteger(row.ProgramID) AS programId, toInteger(row.FBID) AS FBId
MATCH (pr:Program {programId: programId})
MATCH (fb:FB {FBId: FBId})
MERGE (fb)-[rel:CONTAINS]->(pr)
RETURN count(rel)
