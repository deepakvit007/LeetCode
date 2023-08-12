# Write your MySQL query statement below


select t.id 
from Weather as t
join weather as b
on datediff(t.recordDate,b.recordDate) = 1
 where t.temperature > b.temperature 
