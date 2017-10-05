void Abrir_dedao()
{
  motor1.write(50);
}


void Fechar_dedao()
{
  motor1.write(180);
}

void PAPEL()
{
  Abrir_dedao();
  delay(500);
  motor2.write(180);
  motor3.write(180);
}

void PEDRA()
{
  Abrir_dedao();
  delay(500);
  motor2.write(0);
  motor3.write(0);
  delay(500);
  Fechar_dedao();
}

void TESOURA()
{
  Abrir_dedao();
  delay(500);
  motor2.write(180);
  delay(500);
  motor3.write(0);
  Fechar_dedao();
}

