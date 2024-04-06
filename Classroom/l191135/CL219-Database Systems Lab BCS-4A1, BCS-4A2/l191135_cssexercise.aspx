<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="l191135_cssexercise.aspx.cs" Inherits="Lab1_S4.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <link rel="stylesheet" type="text/css" href="l191135_cssexercise.css"/>
    <script src="l191135_jsexercise.js"></script>
</head>

<body >
        <form id="form1" runat="server">
        <center><h1><strong>Currency Converting Web Site</strong></h1>
        <hr>

            </br></br>
            </br></br>
            </br>
            

            <div class="Texts">
            <span>Select Currency Medium:</span></br>
            <asp:DropDownList ID="DropDownList" runat="server" AutoPostBack="False" onchange="selectedMedium();">
                <asp:ListItem Value="0">Select</asp:ListItem>
                <asp:ListItem Value="1">Pakistan(PKR)</asp:ListItem>
                <asp:ListItem Value="2">China(Yuan)</asp:ListItem>
                <asp:ListItem Value="3">UAE(Dirham)</asp:ListItem>
                <asp:ListItem Value="4">JP(Yen)</asp:ListItem>
            </asp:DropDownList>
            </div>

            <hr style="width:320px;">
            <br/>

        <div class="Texts">
            <span>Please enter amount in Rupees to convert to your Selected Medium : </span></br>
            <asp:TextBox ID="TextBox1" runat="server" class="textbox"></asp:TextBox>
        </div>
            
            <br/> 
            <button class="Button" onclick="Conversition_A_to_B()">Convert Rupees to select medium</button> 
            <br/> 
       
            <div class="Texts">
            <span>Amount from rupees to your Chosen Medium: </span></br>
            <asp:TextBox ID="TextBox2" runat="server"  class="textbox"></asp:TextBox>
        </div>
            
            <br/>
            <hr style="width:480px;">
           <br/> 
        
            <div class="Texts">
            <span>Please enter amount in your Chosen Medium to convert to Rupees :  </span></br>
            <asp:TextBox ID="TextBox3" runat="server" class="textbox"></asp:TextBox>
        </div>
            <br/><br/> 

            <button class="Button" onclick="Conversition_B_to_A()">Convert from selected medium to rupees</button> 
            <br/>

        <div class="Texts">
            <span>Amount from your chosen medium to Rupees :  </span></br>
            <asp:TextBox ID="TextBox4" runat="server" class="textbox"></asp:TextBox>
            <br/><br/> 
        </div>

        </br>
        <hr style="width:180px;">
        <button class="ResetButton" onclick="resetAll()">Reset</button> </center>
        
            
        <hr>
        <div class="Texts">
            <span>Your previous Chosen Medium Was :  </span>
            <asp:TextBox ID="TextBox5" runat="server" class="textbox"></asp:TextBox>
            <br/>
        </div>
        <div class="Texts">
            <span>Created by :  </span>
            <asp:TextBox ID="TextBox6" runat="server" class="textbox"></asp:TextBox> 
        </div>
    </form>
</body>
</html>
