// C++ code
//
void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
  delay(500);
  
  // Initialize input and output 
  int input;
  String bonus_score; 
  
  // Prompt User
  Serial.println("\nEnter 1 to 9");
  
  // Wait user to enter an input and parse it into integer
  while(!Serial.available());
  input = Serial.parseInt();
  
  // Handling errors before preceeding to actual logic
  if(input <= 0 || input >=10){
  	Serial.println("Error: Please select numbers from 1 to 9 only!!!");
    return;
  }
  
  // Using if else statement
  if(input >= 1 && input <=3){
    bonus_score = "Bonus Score: " + String(input * 10);
  } else if(input >= 4 && input <=6){
    bonus_score = "Bonus Score: " + String(input * 100);
  } else if(input >=7 && input <= 9){
    bonus_score = "Bonus Score: " + String(input * 1000);
  }
  
  Serial.println(bonus_score);
}