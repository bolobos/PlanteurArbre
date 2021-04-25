//pr l'instant, copier coller d'un autre projetS

String mode = "";
String color = "";

  void setup() 
  {
    Serial.begin (9600);  
  }

  void loop() {
    RetroEtGeekSerial();
    //&mode:auto&color:10

 //exemple de condition 
 if( mode == "auto"){
  // mon action

  mode = "";
 }
 if( color == "quelquechose"){
  // mon action

 color = "";
 }

  }            

  void RetroEtGeekSerial(){  
    if (Serial.available()){
      String inputString = "";
      long temps = millis();
      // boucle blocage temps bandeau led 
      /*
      while(millis() < temps + 1000){
          if (Serial.available()){
              //Serial.println("OK");
             inputString = Serial.readString();
        }
      }
      */ 
      // fin boucle blocage led
      inputString = Serial.readString();// sans boucle blocage temps bandeau led

      char inputChar[inputString.length()+1] ;
      inputString.toCharArray(inputChar,inputString.length()+1);

        // lit toute les commandes separes par des &
        // Read each command pair 
        char* command = strtok(inputChar, "&");
        // boucle sur toutes les commandes
        while (command != 0)
        {
            // decoupe command en deux valeurs , separateur :
            // Split the command in two values
            char* valueCommand = strchr(command, ':');
            if (valueCommand != 0)
            {
                *valueCommand = 0;
                ++valueCommand;         
                // aiguillage par rapport a la valeur de command 
                  if(String(command) == "mode"){
                    mode = String(valueCommand) ;
                  }else if(String(command) == "color"){
                    color = String(valueCommand) ;
                    //secondHand = atoi(valueCommand);
                  }
            }
            // Recherche une nouvelle commande separes pas un &
            // Find the next command in input string
            command = strtok(0, "&");
        }
      delay(500);
      }  
  }