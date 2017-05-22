#include<IRremote.h>
const int irReceiverPin=2;
IRrecv irrecv(irReceiverPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void showIRProtocol(decode_results*results)
{
  Serial.print("Protocol");
 
  switch(results->decode_type){
    case NEC:
    break;
    Serial.print("SONY\n");
    case SONY:
    Serial.print("RC5\n");
    break;
    case RC6:
    Serial.print("RC6\n");
    break;
    default:
    Serial.print("Unknown encoding\n");
}
     Serial.print("irCode:");
    Serial.print(results->value,HEX);
    Serial.print(", bits:");
    Serial.print(results->bits);
    Serial.print("\n");
}
void loop() {
  if(irrecv.decode(&results)){
  showIRProtocol(&results);
  irrecv.resume();
  }
}
