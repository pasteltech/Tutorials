// Maurice Ribble 
// 8-30-2009
// http://www.glacialwanderer.com/hobbyrobotics
// Used Arduino 0017
// This does does some error checking to try to make sure the receiver on this one way RF 
//  serial link doesn't repond to garbage

#define NETWORK_SIG_SIZE 3 //Network Signature Size -

#define VAL_SIZE         2 //Value Size -f
#define CHECKSUM_SIZE    1
#define PACKET_SIZE      (NETWORK_SIG_SIZE + VAL_SIZE + CHECKSUM_SIZE) //Size of the whole packet being sent in one instance

// The network address byte and can be changed 
#define NET_ADDR 5 //can be changed if you want to run other devices without interference

const byte g_network_sig[NETWORK_SIG_SIZE] = {0x8F, 0xAA, NET_ADDR};  // Few bytes used to initiate a transfer

// Sends an unsigned int over the RF network
void writeUInt(unsigned int val)
{
  byte checksum = (val/256) ^ (val&0xFF);
  /*
  Serial.println();
  Serial.println(val);
  Serial.println(val&0xFF);
  Serial.println(3&0xFF);
  */
  
  Serial.write(0xF0);  // This gets reciever in sync with transmitter, 240
  Serial.write(g_network_sig, NETWORK_SIG_SIZE);
  Serial.write((byte*)&val, VAL_SIZE);
  Serial.write(checksum); //CHECKSUM_SIZE


 

 
  
}

// Receives an unsigned int over the RF network
unsigned int readUInt(bool wait)
{
  int pos = 0;          // Position in the network signature
  unsigned int val;     // Value of the unsigned int
  byte c = 0;           // Current byte
  
  if((Serial.available() < PACKET_SIZE) && (wait == false))
  {
    return 0xFFFF; //return 65535
  }
  
  while(pos < NETWORK_SIG_SIZE)
  { 
    while(Serial.available() == 0); // Wait until something is avalible
    c = Serial.read();

    if (c == g_network_sig[pos])
    {
      if (pos == NETWORK_SIG_SIZE-1) //Checksum is the last byte
      {
        byte checksum;

        while(Serial.available() < VAL_SIZE + CHECKSUM_SIZE); // Wait until something is avalible
        val      =  Serial.read();
        val      += ((unsigned int)Serial.read())*256;
        checksum =  Serial.read();
        
        if (checksum != ((val/256) ^ (val&0xFF)))
        {
          // Checksum failed
          pos = -1;
        }
      }
      ++pos;
    }
    else if (c == g_network_sig[0])
    {
      pos = 1;
    }
    else
    {
      pos = 0;
      if (!wait)
      {
        return 0xFFFF;
      }
    }
  }
  return val;
}


