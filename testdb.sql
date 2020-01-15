CREATE TABLE [CustomerData] ( 
	[Name] VARCHAR(50)  NOT NULL,  
	[ContactNumber] BIGINT(10) NOT NULL,
	[EmailId] VARCHAR(100) NOT NULL,
	[PAN] VARCHAR(10) NOT NULL PRIMARY KEY,
	[Age] TINYINT(3) NULL,
	[Room] VARCHAR
);

CREATE TABLE [Rooms] ( 
	[Index] TINYINT(1),
	[RoomType] VARCHAR,
	[Price] INTEGER,
	[Num] TINYINT(3) NOT NULL,
	[Deposit] INTEGER
);


INSERT INTO CustomerData 
VALUES ('Rohit Pai',9969119020,'rohit23110@gmail.com','DBIAA2134K',18,'DELUXE'),
	   ('Remus Lupin',9045662442,'remus.lupin@gmail.com','DHAKD6356H',32,'DELUXE'),
	   ('Annabeth Chase',9045633333,'daughterofathena@gmail.com','JLFDJ8362Y',19,'DELUXE'),
	   ('Seema Pai',9619615112,'spai13@gmail.com','LHFSV4357K',55,'ECONOMY'),
	   ('Legolas Greenleaf',9045603791,'elvenking@gmail.com','KDABF9764I',43,'ECONOMY'),
	   ('Rhaegar Targaryen',9019141523,'dragonrider@gmail.com','NDBAJ4134O',23,'SUITE'),
	   ('Rajaram Pai',9892120945,'kedar304@gmail.com','HFBSK9743P',59,'ECONOMY'),
	   ('Susan Pevensie',9141181491,'susanthegentle@gmail.com','FBSJG7463P',21,'ECONOMY'),
	   ('Peeta Mellark',9045747576,'starcrossedlover@gmail.com','LHFKD7943M',29,'ECONOMY'),
	   ('Harsh Sandesara',9022280471,'sandesara.harsh@gmail.com','HFOHO6854S',18,'DELUXE'),
	   ('Nita Shanbhag',9322402424,'nita.eye@gmail.com','NFHDK4683S',53,'DELUXE'),
	   ('Karan Shah',7932917932,'kbshah2000@gmail.com','HKHDO5715S',18,'ECONOMY'),
	   ('Shashank Patel',7748719872,'shashankcr777@gmail.com','HYIRY5715P',19,'ECONOMY'),
	   ('Stan Lee',9041920114,'cameostan@gmail.com','KHDKH7897G',86,'ECONOMY'),
	   ('Yoda',9046251541,'yodamama@gmail.com','HDKBD7943H',255,'ECONOMY');

INSERT INTO Rooms 
VALUES (1,'ECONOMY',4000,51,4000),
	   (2,'DELUXE',9000,30,9000),
 	   (3,'SUITE',15000,4,15000);

