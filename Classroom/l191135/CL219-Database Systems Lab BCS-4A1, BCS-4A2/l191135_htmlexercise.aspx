<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="l191135_cssexercise.aspx.cs" Inherits="Lab1_S4.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            font-weight: normal;
        }
    </style>
</head>
<body style="background-image: url('https://wonderfulengineering.com/wp-content/uploads/2016/02/wallpaper-background-2.jpg'); background-size:auto;">
        <form id="form1" runat="server">
        <div style="width: 28%; height: 100%; align-content:normal;  padding: 32px;  background-color:#ffffff;border: 2px solid black; border-radius: 96px 16px;">
            <center><asp:Image ID="Image2" ImageUrl="https://media.istockphoto.com/vectors/unique-initial-g-letter-symbol-for-your-best-business-symbol-vector-id1222451396?b=1&k=6&m=1222451396&s=612x612&w=0&h=LAk96CHobMsxlyVUa36fdeYyEfOTr63dJGXObrTkZ9s=" runat="server" Height="239px" Width="213px" /></center>
            </br>
            <h1 style="margin: auto;" class="auto-style1"><strong>Sign Up</strong></h1>
            </br></br>
            First Name:&nbsp;<asp:TextBox ID="txtName" runat="server"></asp:TextBox>
            &nbsp;Last Name:&nbsp;<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            </br></br>
            User Name:&nbsp;<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
            </br></br>
            
            Password:&nbsp;<asp:TextBox ID="txtPassword" TextMode="password" runat="server"></asp:TextBox>
            </br></br>
            Date of Birth:&nbsp;</br><asp:Calendar ID="Calendar1" runat="server"></asp:Calendar>
            </br></br>
            Country:&nbsp;
            <asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem>Select</asp:ListItem>
                <asp:ListItem>Pakistan</asp:ListItem>
                    <asp:ListItem>India</asp:ListItem>
                    <asp:ListItem>China</asp:ListItem>
                    <asp:ListItem>Iraq</asp:ListItem>
            </asp:DropDownList>

            </br></br>
            Gender:&nbsp;
            <asp:RadioButton ID="Male" runat="server" />Male&nbsp;<asp:RadioButton ID="Female" runat="server" />Female
            </br></br>
            <asp:CheckBox ID="EnablePrivacy" runat="server"></asp:CheckBox> Enable Privacy
            </br></br>
            <asp:Button ID="btnSave" Text="Create Account" runat="server" />
            </br></br>
            <asp:CheckBox ID="Remember" runat="server"></asp:CheckBox> Remember me
                
        </div>
    </form>
</body>
</html>
