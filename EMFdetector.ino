// Aaron ALAI EMF Detector May 28th 2009 VERSION 1.1
// aaronalai1@gmail.com
// contains code for averaging sensor data

#define sample 300                   //this is how many samples the device takes per reading
                                                        //more information for #define http://arduino.cc/en/Reference/Define 
int inPin = 4;                                  //analog 5
float val;                                         //where to store info from analog 5
int pin11 = 11;                              //output of red led

float array1[sample];                      //creates an array with number of elements equal to "sample" 
                                                       //more information about arrays http://arduino.cc/en/Reference/Array


//unsigned long averaging;         //the program uses this variable to store the sum of each array it makes
float averaging;

void setup() {
 
  Serial.begin(9600);
 
}

void loop() {
                    
  for(int i = 0; i < sample; i++){              //this code tells the program to fill each element in the array we made with
     array1[i] = analogRead(inPin);       //information from the antenna wire coming out of the Arduino
     averaging += array1[i];                      //more information about for loops http://arduino.cc/en/Reference/For
  }                                                               //the averaging line is simply saying: add averaging to whatever is in array position i
                                                                  //averaging += array[i] is the same as averaging = averaging + array[i]
                                                                  //for more information about += http://arduino.cc/en/Reference/IncrementCompound
  
  
  
  val = averaging / sample;                   //here the program takes the sum of all numbers in array1, and divides by the number of elements "sample"
  val = val*100;

  val = constrain(val, 0, 100);               //this constrains the variable value to between two numbers 0 and 100    
Serial.print("before map: "); 
Serial.println(val); 
  
  if(val>20.0){                             //use 40.0 when connected to laptop
//  if(val>30.0){
    val = map(val, 0.0, 100, 0.0, 255.0);      //for more information about constrain http://arduino.cc/en/Reference/Constrain   
  
    analogWrite(pin11, val);
  }    //the map statement tells the program to map out 0-100 to 0-255, 255 is 
  else{analogWrite(pin11,0);}
                                                                //the threashold of analogWrite for more information about map http://arduino.cc/en/Reference/Map
  averaging = 0;                                 //this line of code sets averaging back to zero so it can be used again
  


//  if(val > 0) 
//  Serial.print("after map: "); 
//    Serial.println(val);                                // use output to aid in calibrating
  delay(10);
}
