question1
Create View Cecheck
as
select creators.c_id, creators.first_name, creators.email from creators join art_piece_details
on creators.c_id = art_piece_details.creator_id join piece_type
on piece_type.type_id = art_piece_details.type_id where creators.creator_Trainer_id in
(select c_id from creators)
and piece_type.type_name = 'scenery'

question2
Create Procedure verifyid
@id int,
@res int = 0 output
as begin 
if @id in (select c_id from creators_trainers ) 
begin
set @result = 1
end
end

question3
Create View all_pieces_total
as select art_id, total_sales from(
select art_piece_details.art_id, 0 as total_sales
from art_piece_details
where art_piece_details.art_id != 
(select art_piece_details.art_id	From art_piece_details join sale on sale.art_id = art_piece_details.art_id
join payment_mode on sale.payment_mode_id = payment_mode.p_id where payment_mode.payment_mode = 'cash')
union 
select art_piece_details.art_id, count(art_piece_details.art_id) as total_sales
From art_piece_details join sale on sale.art_id = art_piece_details.art_id
join payment_mode on sale.payment_mode_id = payment_mode.p_id
where payment_mode.payment_mode = 'cash' group by art_piece_details.art_id) as p

question4
create trigger sCheck
on sale instead of insert
as begin

if (select quantity from inserted) > (select quantity_available from art_pieces where art_id 
=  (select art_id from inserted)) 
begin
print'Error'
RollBack
end
else
begin
update art_pieces
set quantity_available = quantity_available - (select inserted.quantity from inserted)
insert into sale values ((select s_id from inserted), 
(select art_id from inserted),
(select date_of_sale from inserted),
(select quantity from inserted),
(select payment_mode_id from inserted))
end
end

question5
create trigger CTcheck
on creators after insert as begin
if (select inserted.c_id from inserted) = (select inserted.creator_Trainer_id from inserted)
begin
print'same id not allowed.'
RollBack
end
end
