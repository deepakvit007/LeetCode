# Write your MySQL query statement below
# select name from Customer where referee_id <> 2 || referee_id is NULL
select name from Customer where IFNULL(referee_id ,0) <> 2