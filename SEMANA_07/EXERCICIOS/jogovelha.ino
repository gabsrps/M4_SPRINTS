//Gabriel Rocha Pinto Santos (Gabs)
#include <WiFi.h>

#define ledX 6
#define ledO 7

const char* ssid     = "gabsrps";
const char* password = "senha1dois3";
char redeIP[50] = "";

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
    
    pinMode(ledX, OUTPUT);
    pinMode(ledO, OUTPUT);

    delay(10);

    digitalWrite(ledX, HIGH);
    digitalWrite(ledO, LOW);

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("WiFi connected! - ");
    Serial.print("IP address: ");
    IPAddress IP = WiFi.localIP();
    strcpy(redeIP,IP.toString().c_str());
    Serial.println(redeIP);
    
    server.begin();

}

void loop(){
 WiFiClient client = server.available();   

  if (client) {                           
    Serial.println("New Client.");       
    String currentLine = "";          
    while (client.connected()) {        
      if (client.available()) {         
        char c = client.read();           
        Serial.write(c);             
        if (c == '\n') {                  

          
          if (currentLine.length() == 0) {
            
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            
            client.println("<!DOCTYPE html>");
            client.println("<html lang='en'>");
            client.println("<head>");
            client.println("<meta charset='UTF-8'>");
            client.println("<meta http-equiv='X-UA-Compatible' content='IE=edge'>");
            client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
            client.println("<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js'></script>");
            client.println("<title>Velha-Velha</title>");
            client.println("</head>");

            client.println("<body onload='CreateMinSquare()'>");
            client.println("<main>");
            client.println("<div class='title'><h1>Jogo da Velha da Velha</h1></div>");
            client.println("<div class='big-container'>");
            client.println("<div class='container'>");
            client.println("<div class='square' id='SQ0' onclick='CreateVelha(0)'>");
            client.println("<div class='min-container' id='c0'></div>");
            client.println("</div>");
            client.println("<div class='square' id='SQ1' onclick='CreateVelha(1)'>");
            client.println("<div class='min-container' id='c1'></div>");
            client.println("</div>");
            client.println("<div class='square' id='SQ2' onclick='CreateVelha(2)'>");
            client.println("<div class='min-container' id='c2'></div>");
            client.println("</div>");
            client.println("<div class='square' id='SQ3' onclick='CreateVelha(3)'>");
            client.println("<div class='min-container' id='c3'></div>");
            client.println("</div>");
            client.println("<div class='square' id='SQ4' onclick='CreateVelha(4)'>");
            client.println("<div class='min-container' id='c4'></div>");
            client.println("</div>");
            client.println("<div class='square' id='SQ5' onclick='CreateVelha(5)'>");
            client.println("<div class='min-container' id='c5'></div>");
            client.println("</div>");
            client.println("<div class='square' id='SQ6' onclick='CreateVelha(6)'>");
            client.println("<div class='min-container' id='c6'></div>");
            client.println("</div>");
            client.println("<div class='square' id='SQ7' onclick='CreateVelha(7)'>");
            client.println("<div class='min-container' id='c7'></div>");
            client.println("</div>");
            client.println("<div class='square' id='SQ8' onclick='CreateVelha(8)'>");
            client.println("<div class='min-container' id='c8'></div>");
            client.println("</div>");
            client.println("</div>");
            client.println("<br><div class='display' id='selected'></div>");
            client.println("<div class='container' id='velha2'></div>");
            client.println("</div>");
            client.println("</main>");


            client.println("<style>");
            client.println("* {");
            client.println("    padding: 0;");
            client.println("    margin: 0;");
            client.println("}");
            client.println(".title {");
            client.println("    text-align: center;");
            client.println("    font-size: 30px;");
            client.println("    margin-top: 2em;");
            client.println("    margin-bottom: 2em;");
            client.println("}");
            client.println(".display {");
            client.println("    font-size: 15px;");
            client.println("    text-align: center;");
            client.println("    margin-top: 1em;");
            client.println("    margin-bottom: 1em;");
            client.println("}");
            client.println(".big-container {");
            client.println("    display: flex;");
            client.println("    flex-direction: row;");
            client.println("    justify-content: space-between;");
            client.println("}");
            client.println(".container {");
            client.println("    margin: 0 auto;");
            client.println("    display: grid;");
            client.println("    grid-template-columns: 33% 33% 33%;");
            client.println("    grid-template-rows: 33% 33% 33%;");
            client.println("    max-width: 300px;");
            client.println("}");
            client.println(".min-container {");
            client.println("    margin: 0 auto;");
            client.println("    display: grid;");
            client.println("    grid-template-columns: 33% 33% 33%;");
            client.println("    grid-template-rows: 33% 33% 33%;");
            client.println("    max-width: 100px;");
            client.println("}");
            client.println(".square {");
            client.println("    border: 3px solid black;");
            client.println("    min-width: 99px;");
            client.println("    min-height: 99px;");
            client.println("    display: flex;");
            client.println("    justify-content: center;");
            client.println("    align-items: center;");
            client.println("    font-size: 45px;");
            client.println("    cursor: pointer;");
            client.println("}");
            client.println(".square-selected {");
            client.println("    border: 4px solid lawngreen;");
            client.println("    min-width: 99px;");
            client.println("    min-height: 99px;");
            client.println("    display: flex;");
            client.println("    justify-content: center;");
            client.println("    align-items: center;");
            client.println("    font-size: 45px;");
            client.println("    cursor: pointer;");
            client.println("}");
            client.println(".min-square {");
            client.println("    border: 1px solid black;");
            client.println("    min-width: 31.5px;");
            client.println("    min-height: 31.5px;");
            client.println("    display: flex;");
            client.println("    justify-content: center;");
            client.println("    align-items: center;");
            client.println("    font-size: 15px;");
            client.println("}");
            client.println(".square2 {");
            client.println("    border: 3px solid black;");
            client.println("    min-width: 99px;");
            client.println("    min-height: 99px;");
            client.println("    display: flex;");
            client.println("    justify-content: center;");
            client.println("    align-items: center;");
            client.println("    font-size: 45px;");
            client.println("    cursor: pointer;");
            client.println("}");
            client.println(".playerX {");
            client.println("    color: red;");
            client.println("}");
            client.println(".playerO {");
            client.println("    color: blue;");
            client.println("}");
            client.println("</style>");


            client.println("<script>");
            client.println("const x = `<b class='playerX'>X</b>`;");
            client.println("const o = `<b class='playerO'>O</b>`;");
            client.println("var currentPlayer = x;");
            client.println("var firstPlay = true;");
            client.println("var played = false;");
            client.println("var endGame = false;");
            client.println("var playerX = [];");
            client.println("var playerO = [];");
            client.println("var playerT = [];");
            client.println("var winX = [];");
            client.println("var winO = [];");
            client.println("var winT = [];");
            client.println("var Xgain = [];");
            client.println("var Ygain = [];");
            client.println("var Tgain = [];");
            client.println("var idClass = '';");

            client.println("function CheckWinner(gained, player){");
            client.println("    const writewinner = document.getElementById('selected');");
            client.println("    if(gained.includes(0)&&gained.includes(1)&&gained.includes(2)||");
            client.println("    gained.includes(3)&&gained.includes(4)&&gained.includes(5)||");
            client.println("    gained.includes(6)&&gained.includes(7)&&gained.includes(8)||");
            client.println("    gained.includes(0)&&gained.includes(3)&&gained.includes(6)||");
            client.println("    gained.includes(1)&&gained.includes(4)&&gained.includes(7)||");
            client.println("    gained.includes(2)&&gained.includes(5)&&gained.includes(8)||");
            client.println("    gained.includes(0)&&gained.includes(4)&&gained.includes(8)||");
            client.println("    gained.includes(2)&&gained.includes(4)&&gained.includes(6)){");
            client.println("        writewinner.innerHTML = `<h1>${player} VENCEU!</h1>`;");
            client.println("        endGame = true;");
            client.println((String)"        $.get('http://"+redeIP+"/VICTORY', ()=>{console.log('VITÓRIA!!!')});");
            client.println("    }");
            client.println("}");

            client.println("function CheckVelha(pos, total){");
            client.println("    const writevelha = document.getElementById('selected');");
            client.println("    if(total.includes(0)&&total.includes(1)&&total.includes(2)&&");
            client.println("    total.includes(3)&&total.includes(4)&&total.includes(5)&&");
            client.println("    total.includes(6)&&total.includes(7)&&total.includes(8)){");
            client.println("        Tgain.push(pos);");
            client.println("        if(Tgain.includes(0)&&Tgain.includes(1)&&Tgain.includes(2)&&");
            client.println("        Tgain.includes(3)&&Tgain.includes(4)&&Tgain.includes(5)&&");
            client.println("        Tgain.includes(6)&&Tgain.includes(7)&&Tgain.includes(8)){");
            client.println("            writevelha.innerHTML = '<h1>VELHA!!!</h1>';");
            client.println("            endGame = true;");
            client.println("        }");
            client.println("   }");
            client.println("}");

            client.println("function CheckWin(pos, player){");
            client.println("    const writewin = document.getElementById('SQ'+pos);");
            client.println("    winT = playerT.map(a=>a-9*pos);");
            client.println("    if(player == x){");
            client.println("        winX = playerX.map(a=>a-9*pos);");
            client.println("        if(winX.includes(0)&&winX.includes(1)&&winX.includes(2)||");
            client.println("        winX.includes(3)&&winX.includes(4)&&winX.includes(5)||");
            client.println("        winX.includes(6)&&winX.includes(7)&&winX.includes(8)||");
            client.println("        winX.includes(0)&&winX.includes(3)&&winX.includes(6)||");
            client.println("        winX.includes(1)&&winX.includes(4)&&winX.includes(7)||");
            client.println("        winX.includes(2)&&winX.includes(5)&&winX.includes(8)||");
            client.println("        winX.includes(0)&&winX.includes(4)&&winX.includes(8)||");
            client.println("        winX.includes(2)&&winX.includes(4)&&winX.includes(6)){");
            client.println("            writewin.innerHTML = x;");
            client.println("            Xgain.push(pos);");
            client.println("            Tgain.push(pos);");
            client.println("            CheckWinner(Xgain, player);");
            client.println("        } else CheckVelha(pos, winT);");
            client.println("    }");
            client.println("    else if(player == o){");
            client.println("        winO = playerO.map(a=>a-9*pos);");
            client.println("        if(winO.includes(0)&&winO.includes(1)&&winO.includes(2)||");
            client.println("        winO.includes(3)&&winO.includes(4)&&winO.includes(5)||");
            client.println("        winO.includes(6)&&winO.includes(7)&&winO.includes(8)||");
            client.println("        winO.includes(0)&&winO.includes(3)&&winO.includes(6)||");
            client.println("        winO.includes(1)&&winO.includes(4)&&winO.includes(7)||");
            client.println("        winO.includes(2)&&winO.includes(5)&&winO.includes(8)||");
            client.println("        winO.includes(0)&&winO.includes(4)&&winO.includes(8)||");
            client.println("        winO.includes(2)&&winO.includes(4)&&winO.includes(6)){");
            client.println("            writewin.innerHTML = o;");
            client.println("            Ygain.push(pos);");
            client.println("            Tgain.push(pos);");
            client.println("            CheckWinner(Ygain, player);");
            client.println("        } else CheckVelha(pos, winT);");
            client.println("    }");
            client.println("}");

            client.println("function Play(index, pos){");
            client.println("    console.log(currentPlayer + ' jogou no ' + index);");
            client.println("    if(playerX.includes(index)){alert('X já jogou aí'); return;}");
            client.println("    if(playerO.includes(index)){alert('O já jogou aí'); return;}");
            client.println("    playerT.push(index);");
            client.println("    if(currentPlayer == x){");
            client.println("        playerX.push(index);");
            client.println("        document.getElementById(`sq${index}`).innerHTML = x;");
            client.println("        document.getElementById(`msq${index}`).innerHTML = x;");
            client.println("        CheckWin(pos, currentPlayer);");
            client.println("        currentPlayer = o;");
            client.println((String)"        $.get('http://"+redeIP+"/O', ()=>{console.log('Vez do O!')});");
            client.println("    }");
            client.println("    else if(currentPlayer == o){");
            client.println("        playerO.push(index);");
            client.println("        document.getElementById(`sq${index}`).innerHTML = o;");
            client.println("        document.getElementById(`msq${index}`).innerHTML = o;");
            client.println("        CheckWin(pos, currentPlayer);");
            client.println("        currentPlayer = x;");
            client.println((String)"        $.get('http://"+redeIP+"/X', ()=>{console.log('Vez do X!')});");
            client.println("    }");
            client.println("    played = true;");
            client.println("    if(!endGame){");
            client.println("        setTimeout(() =>{");
            client.println("            document.getElementById(idClass).classList.toggle('square-selected');");
            client.println("            var id = Math.floor(Number(index)%9);");
            client.println("            CreateVelha(id);");
            client.println("        }, 250);");
            client.println("    }");
            client.println("}");

            client.println("function CreateMinSquare(){");
            client.println("    for(let i=0, N=0, n=0; i<9; i++, N++){");
            client.println("        for(let j=0; j<9; j++){");
            client.println("            document.getElementById(`c${N}`).innerHTML += `<div class='min-square' id='msq${n}'></div>`;");
            client.println("            n++;");
            client.println("        }");
            client.println("    }");
            client.println("}");

            client.println("function CreateVelha(index){");
            client.println("    if(!firstPlay && !played || endGame) return;");
            client.println("    if(firstPlay) firstPlay = false;");
            client.println("    played = false;");
            client.println("    let squared = Number(index)*9;");
            client.println("    let midsquared = squared;");
            client.println("    let finalsquared = squared+9;");
            client.println("    let velha = `");
            client.println("    <div class='square2' id='sq${squared}' onclick='Play(${squared}, ${index})'></div>");
            client.println("    <div class='square2' id='sq${squared+1}' onclick='Play(${squared+1}, ${index})'></div>");
            client.println("    <div class='square2' id='sq${squared+2}' onclick='Play(${squared+2}, ${index})'></div>");
            client.println("    <div class='square2' id='sq${squared+3}' onclick='Play(${squared+3}, ${index})'></div>");
            client.println("    <div class='square2' id='sq${squared+4}' onclick='Play(${squared+4}, ${index})'></div>");
            client.println("    <div class='square2' id='sq${squared+5}' onclick='Play(${squared+5}, ${index})'></div>");
            client.println("    <div class='square2' id='sq${squared+6}' onclick='Play(${squared+6}, ${index})'></div>");
            client.println("    <div class='square2' id='sq${squared+7}' onclick='Play(${squared+7}, ${index})'></div>");
            client.println("    <div class='square2' id='sq${squared+8}' onclick='Play(${squared+8}, ${index})'></div>");
            client.println("    `;");
            client.println("    document.getElementById('velha2').innerHTML = velha;");
            client.println("    while(midsquared<finalsquared){");
            client.println("        if(playerX.includes(midsquared)) document.getElementById(`sq${midsquared}`).innerHTML = x;");
            client.println("        if(playerO.includes(midsquared)) document.getElementById(`sq${midsquared}`).innerHTML = o;");
            client.println("        midsquared++;");
            client.println("    }");
            client.println("    document.getElementById('selected').innerHTML = `<h1>Jogue ${currentPlayer}!</h1>`;");
            client.println("    idClass = 'SQ'+index;");
            client.println("    document.getElementById(idClass).classList.toggle('square-selected');");
            client.println("    if(Tgain.includes(index)){");
            client.println("        firstPlay = true;");
            client.println("        document.getElementById(idClass).classList.toggle('square-selected');");
            client.println("        document.getElementById('selected').innerHTML = `<h1>Onde quiser, ${currentPlayer}!</h1>`;");
            client.println("    }");
            client.println("}");
            client.println("</script>");
            client.println("</html>");

            
            client.println();
            break;
          } else {    
            currentLine = "";
          }
        } else if (c != '\r') { 
          currentLine += c;     
        }


        if (currentLine.endsWith("GET /O")) {
          digitalWrite(ledX, LOW);
          digitalWrite(ledO, HIGH);
          Serial.println("Vez do O!");
        }
        if (currentLine.endsWith("GET /X")) {
          digitalWrite(ledX, HIGH);
          digitalWrite(ledO, LOW);
          Serial.println("Vez do X!");
        }
        if (currentLine.endsWith("GET /VICTORY")) {
          digitalWrite(ledX, LOW);
          digitalWrite(ledO, LOW);
          delay(100);
          digitalWrite(ledX, HIGH);
          delay(250);
          for(int i=0; i<16; i++){
            digitalWrite(ledX, LOW);
            digitalWrite(ledO, HIGH);
            delay(250);
            digitalWrite(ledX, HIGH);
            digitalWrite(ledO, LOW);
            delay(250);
            Serial.println("Venceuuuu!!!");
          }
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}