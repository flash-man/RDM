
import processing.serial.*; 
import de.bezier.data.sql.*; 
Serial port;
MySQL dbconnection;
int prevLEDState = 0; 


void setup()
{
  port = new Serial(this, Serial.list()[0], 9600); 
  port.bufferUntil('\n');
  
  String user     = "user";
  String pass     = "pass";
  String database = "database";

  dbconnection = new MySQL( this, "hosting", database, user, pass ); 
  dbconnection.connect();
}

void draw()
{    
  dbconnection.query( "SELECT * FROM comand WHERE id = (SELECT max(id) FROM comand)" ); 
  while (dbconnection.next()) 
   {
    int a = dbconnection.getInt("action");
    int c = dbconnection.getInt("comand_handler");
    
    if (a == 0) port.write('0');
    if (a == 1) port.write('1');
    if (a == 2) port.write('2');
    if (c == 3)  port.write('3');   
    if (c == 4)  port.write('4');
     
   }
  
  delay(100);
}