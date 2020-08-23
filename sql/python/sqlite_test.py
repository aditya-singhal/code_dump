
import sqlite3

conn = sqlite3.connect('/home/aditya/workspace/repository/kavach_z/middleware/sensor/hawk/build/logs/logs_hawk.db')
print "Opened database successfully";

# conn.execute("CREATE TABLE m8_server_logs (	\
# 	MESSAGE_DATE DATE NOT NULL,				\
# 	MESSAGE_TIME TIME NOT NULL,				\
# 	TYPE NOT_NULL INT NOT NULL,				\
# 	MESSAGE BLOB NOT NULL );")

#conn.execute("INSERT INTO m8_server_logs (MESSAGE_DATE, MESSAGE_TIME, TYPE, MESSAGE ) \
#     VALUES (Date(), Time('now','localtime'), 1, 'Hello World!')");

#conn.commit()

# output = conn.execute("SELECT LOCALTIME");
# for row in output:
# 	print row[0]

#output = conn.execute("SELECT * from m8_server_logs where MESSAGE_TYPE = 'DEBUG'")
output = conn.execute("SELECT * from hawk ")
for row in output:
	print row

conn.close()
