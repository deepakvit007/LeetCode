 select machine_id,round((select avg(timestamp) from Activity as a1 where activity_type = "end" and a1.machine_id = a.machine_id )- 
(select avg(timestamp) from Activity as a1 where activity_type = "start" and a1.machine_id = a.machine_id ),3) as processing_time from Activity as a

group by machine_id

