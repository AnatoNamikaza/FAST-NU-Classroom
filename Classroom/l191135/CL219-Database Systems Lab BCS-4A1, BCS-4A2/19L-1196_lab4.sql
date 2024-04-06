
--select cardTypeID, count(cardTypeID) from [card] group by cardTypeID

--select cardNum, [name] from [user] join usercard 
--on [user].userId = usercard.userID
--where cardNum in ( select cardNum From [card] where (balance >= 2000 and balance <= 4000)

--select [name] from [user] 
--intersect select [name] from [user] 
--where userId not in ( Select userID From [usercard] )

--select [name] from [User] left join usercard on [user].userId = usercard.userID
--where [User].userId not in ( select UserCard.userID from [UserCard] )

--select '','', [name] from [user]
--where userId in(select userID from [usercard] where cardNum not in
--(select cardNum from [Transaction] where  year(transDate) = year(getdate())-1))
--union select cardnum, cardTypeID,'' from [Card]
--where cardNum not in (select cardNum from [Transaction] where  year(transDate) = year(getdate())-1)

--select [card].cardNum, [card].cardTypeID, [user].name from [user] left join [usercard] on [user].userId = [usercard].userID
--left join [Card] on [usercard].cardNum = [card].cardNum left join [Transaction] on [card].cardNum = [Transaction].cardNum
--where [usercard].cardNum not in (select [usercard].cardNum from [user] left join [usercard] on [user].userId = [usercard].userID
--left join [card] on [usercard].cardNum = [card].cardNum left join [Transaction] on [card].cardNum = [Transaction].cardNum	where  year(transDate) = year(getdate())-1)

--select [Card].cardTypeID, count([Transaction].cardNum)
--from [Card] left Join [Transaction] on [card].cardNum = [Transaction].cardNum
--where (year([Transaction].transDate) >= 2015 and 2017 >= year([Transaction].transDate))
--group by [Card].cardTypeID
--Having sum([Transaction].amount) > 6000  

--select [user].userId, [user].name, [user].phoneNum, [user].city, [usercard].cardNum, [card].cardTypeID
--from [user] left join [usercard] on [user].userId = [usercard].userID
--left Join [card] on [usercard].cardNum = [card].cardNum where dateadd(month, 3, getdate())  > [card].expireDate

--select userId, [name] from [user] where [name] not in ( 
--select [user].[name] from [user] left join [usercard] on [user].userId = [usercard].userID
--left join [card] on [usercard].cardNum = [card].cardNum group by [user].name having sum([Card].balance) > 50000)

--select card1.cardNum, card2.cardNum from [Card] as card1, [Card] as card2
--where card1.cardNum != card2.cardNum and year(card1.expireDate) = year(card2.expireDate)

--select user1.[name], user2.[name] from [user] as user1, [user] as user2
--where user1.[name] != user2.[name] and substring(user2.[name], 1, 1) = substring(user1.[name], 1, 1)

--select [user].name, [user].userId from [user]
--where [user].userId in (
--select [user].userId from [usercard] left Join [card] on [card].cardNum = [usercard].cardNum
--where [card].cardNum = 1
--intersect
--select [user].userId from [usercard] left Join [card] on [card].cardNum = [usercard].cardNum
--where [card].cardNum = 2)

--select [user].city, count([User].userId), sum([Transaction].amount) 
--from [user] left join [usercard] on [user].userId = [usercard].userID
--left join [Transaction] on [Transaction].cardNum = [usercard].cardNum
--group by [user].city