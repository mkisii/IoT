viod connectToIntewrnet(){
  // to make an attempt to connect with DHCP
  if (Ethernet.begin(mac) ==0)
  {
    Serial.print("[ERROR] Failed to Configure Ethernet using DHCP);

    //DHCP FAILED
    Ethernet.begin(mac, staticIP);
  }
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
