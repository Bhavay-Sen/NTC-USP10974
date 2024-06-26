/* @AUTHOR : BHAVAY SEN */  

int         Ro = 10000, 
            Vin = 5, 
            Beta = 3978, 
            Vout = 0, 
            To = 293.15, 
            R2 = 1000;
            
float       R1 = 0.00,
            Tc = 0.00,
            Tk = 0.00; 

void setup(){
    Serial.begin(9600);
    pinMode(A0, INPUT); 
}

void loop(){
    Vout = analogRead(A0);
    R1 = calculateThermistorResistance(R2, Vin, Vout);
    Tk = calculateTempKelvin(To, R1, Ro, Beta);
    Tc = Tk - 293.15;
    Serial.print("Temperature : ");
    Serial.println(Tc);
}

float calculateThermistorResistance(int R, int Vi, int Vo){
    float Rth = 0;
    Rth = ((Vi - Vo) * R) / Vo ;
    return Rth;
}

float calculateTempKelvin(int To, int R, int Ro, int Beta){
    float Tkel = 0.0;
    Tkel = 1 / ( (1 / To) + ( (ln(R/Ro)) / Beta ) );
    return Tkel;
}
