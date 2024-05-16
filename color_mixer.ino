// C++ code
//

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String color_1;
  String color_2; 
  String output;
  
  Serial.println("\nSelect Colors from Red, Blue, and Yellow. Enter it one by one\n");
  
  // Color 1
  while(true){
    while(!Serial.available());
    color_1 = Serial.readString();
    color_1.toLowerCase();
    
    if(checkColor(color_1)){
      break;
    }
    Serial.println("Error: Invalid color. Please enter red, blue, or yellow.");
  }
	
  Serial.print("Chosen Color 1: ");
  Serial.println(color_1);
  
  // Color 2 - We loop this only exclusively if the second input has validation error
  while(true){
    while(!Serial.available());
    color_2 = Serial.readString();
    color_2.toLowerCase();
    
    if(checkColor(color_2)){
      break;
    }
    Serial.println("Error: Invalid color. Please enter red, blue, or yellow.");
  }
  
  Serial.print("Chosen Color 2: ");
  Serial.println(color_2);
  
  output = "Mix Result: " + mixColors(color_1, color_2);
  Serial.println(output);
 
  delay(200);
  
}

// color validator 
boolean checkColor(String color){
	return (color == "red" || color == "yellow" || color == "blue");
} 

String mixColors(String color1, String color2){
  // if color 1 and color 2 are the same
  if(color1 == color2){
    return color1;
  } 
  if (color1 == "red" && color2 == "blue" || color1 == "blue" && color2 == "red") {
    return "purple";
  } else if (color1 == "red" && color2 == "yellow" || color1 == "yellow" && color2 == "red") {
    return "orange";
  } else if (color1 == "blue" && color2 == "yellow" || color1 == "yellow" && color2 == "blue") {
    return "green";
  } else {
    return "unknown";
  }

}