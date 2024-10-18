uint32_t arr_index = 6;
char chars[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int code[6] = { 0, 0, 0, 0, 0, 0 };

void set_next_code(uint32_t index = 5)
{
  // Increase the number at the code
  code[index]++;
  if (code[index] == 16)
  {
    code[index] = 0;
    if (index > 0)
    {
      return set_next_code(index-1);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  set_next_code();

  // Last code always starts with '30'
  Serial.print("30");
  for (uint16_t i = 0; i < 6; i++)
  {
    Serial.print(chars[code[i]]);
  }
  Serial.println();
  delay(50);
}
