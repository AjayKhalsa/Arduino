#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;


void setup() 
{
 Serial.begin(9600);
 while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  if (SD.exists("datalog.txt")) {
    Serial.println("datalog.txt exists.");
  } else {
    Serial.println("datalog.txt doesn't exist.");
  }

  // open a new file and immediately close it:
  Serial.println("Creating datalog.txt...");
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  dataFile.close();

  // Check to see if the file exists:
  if (SD.exists("datalog.txt")) {
    Serial.println("datalog.txt exists.");
  } else {
    Serial.println("datalog.txt doesn't exist.");
  }

 int i;
   int j;
   int dataArray[15] = {1,j,350,351,352,353,354,25,27,58,15000,998,9,30,2};

 for(i=0;i<100;i++)
 {
     dataArray[1]=i;
 
     File dataFile = SD.open("datalog.txt", FILE_WRITE);
     
     if (dataFile)
     {
         for(j=0;j<15;j++)
        {
         dataFile.print(dataArray[j]);
         dataFile.print("   ");
         Serial.print(dataArray[j]);
         Serial.print("\t");
        }
         dataFile.println();
         dataFile.close();
         Serial.print("\n");
     }

     else
     {
         Serial.println("error opening datalog.txt");
     }
     Serial.print("i is: ");
     Serial.println(i);
    
  }

}
void loop()
{
} 

  
 
  
