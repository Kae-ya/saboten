# shock物

shock物（ショックブツ）はArduinoを用いてセンサーで取得した生育環境を参考に植物の気持ちを可視化するシステムです。

## 使用したセンサ
  ・温度センサ  
  ・湿度センサ  
  ・照度センサ  
  ・土壌センサ  
  →植物がおかれている環境の情報を取得します。  
   
  ・水位センサ  
  →自動で水やりをする機能で使用します。  
   
## システムの説明
  センサから環境の情報を取得し、センサの値がしきい値を超えたときLCDモニターにメッセージを表示します。  
  土が乾いている場合は接続されたポンプを使って自動で水やりをします。  
  環境が良い場合は笑顔の絵札、2つ以上のセンサの値がしきい値を超えたときは泣き顔の絵札が掲げられます。  
  水が無くなった場合は、他のセンサの値がしきい値を超えていなくても泣き顔の絵札が掲げられます。
