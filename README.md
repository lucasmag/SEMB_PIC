# SEMB_PIC
Projeto para disciplina de SEMB na plataforma PIC

Esse projeto vai se consistir de duas partes principais, uma feita no computador usando python e outra na plataforma embarcada 
pic18f4520(talvez 18f4685) em C.

Python:
 script "upload" vair abrir um arquivo .pgm(P5), pode ser feito usando módulo numpy e/ou image, extrair os pixels da imagem
 carregada e mandá-los serialmente para uma porta USB do pc usando o módulo pySerial. Na porta USB haverá um adaptador 
 serial-usb pl2303 que mandará o sinal na porta USB para o pic.
 
 script "download" vai fazer o processo inverso do "upload" vai ler a porta USB do pc,guardar as informações que forem recebidas
 serialmente em uma estrutura e salvar os dados em um arquivo de formato .pgm(P5).
 
C:
  rotinas de interrupção UART para ler/enviar dados pela comunicação serial do pic que estarão conectadas ao pc pelo adaptador
  pl2303. Quando houver envio de dados do pc para o pic, este será notificado e lerá os dados recebidos, depois irá gravar
  na memória flash e em seguida computar o filtro de Roberts Cross e salvar os novos dados na mesma área da memória flash.
  Quando o pc requisitar os dados, o pic enviará serialmente os dados e o script "download" em python no pc ficará responsável
  por montar a imagem.
  
Depois será feito um hardware específico conectando cada componente para facilitar o uso do projeto. Os componentes usados serão:
 -1 pic 18f(4520 ou 4685)
 -1 módulo adaptador serial/usb pl2303
 -3 leds (indicador de power e funcionamento do pic; indicador de comunicação entre pic e pc; indicador de processamento do Roberts)
 -(Opcional) 2 botões (1 para computar filtro de Roberts; 1 para limpar flash)
 -A alimentação será fornecida pela própria porta USB do pc (5v).
