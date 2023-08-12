# Write your MySQL query statement below


select b.id 
from Weather as t
join weather as b
on datediff(b.recordDate,t.recordDate) = 1 where t.temperature < b.temperature 
