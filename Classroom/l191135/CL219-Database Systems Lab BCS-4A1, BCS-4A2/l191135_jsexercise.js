var Conversion = 0;
var Last = "";

function selectedMedium() {
    document.getElementById("TextBox1").value = "";
    document.getElementById("TextBox2").value = "";
    document.getElementById("TextBox3").value = "";
    document.getElementById("TextBox4").value = "";
    document.getElementById("TextBox5").value = Last;
}

function Conversition_A_to_B() {
    Conversion = parseInt(document.getElementById("DropDownList").value)

    if (Conversion == 1) {
        Last = "Pakistan(PKR)";
    }
    else if (Conversion == 2) {
        Last = "China(Yuan)";
    }
    else if (Conversion == 3) {
        Last = "UAE(Dirham)";
    }
    else if (Conversion == 4) {
        Last = "JP(Yen)";
    }

    if (Conversion == 1) {
        document.getElementById("TextBox2").value = parseFloat(document.getElementById("TextBox1").value);
    }
    else if (Conversion == 2) {
        document.getElementById("TextBox2").value = parseFloat((document.getElementById("TextBox1").value) * 0.042);
    }
    else if (Conversion == 3) {
        document.getElementById("TextBox2").value = parseFloat((document.getElementById("TextBox1").value) * 0.024);
    }
    else if (Conversion == 4) {
        document.getElementById("TextBox2").value = parseFloat((document.getElementById("TextBox1").value) * 0.69);
    }
}

function Conversition_B_to_A() {
    Conversion = parseInt(document.getElementById("DropDownList").value)

    if (Conversion == 1) {
        Last = "Pakistan(PKR)";
    }
    else if (Conversion == 2) {
        Last = "China(Yuan)";
    }
    else if (Conversion == 3) {
        Last = "UAE(Dirham)";
    }
    else if (Conversion == 4) {
        Last = "JP(Yen)";
    }

    if (Conversion == 1) {
        document.getElementById("TextBox4").value = parseInt(document.getElementById("TextBox3").value);
    }
    else if (Conversion == 2) {
        document.getElementById("TextBox4").value = parseFloat((document.getElementById("TextBox3").value) * 23.90);
    }
    else if (Conversion == 3) {
        document.getElementById("TextBox4").value = parseFloat((document.getElementById("TextBox3").value) * 42.40);
    }
    else if (Conversion == 4) {
        document.getElementById("TextBox4").value = parseFloat((document.getElementById("TextBox3").value) * 1.43);
    }
}

function resetAll() {
    document.getElementById("DropDownList").value = "Select";
    document.getElementById("TextBox1").value = "";
    document.getElementById("TextBox2").value = "";
    document.getElementById("TextBox3").value = "";
    document.getElementById("TextBox4").value = "";
    document.getElementById("TextBox5").value = Last;
    document.getElementById("TextBox6").value = "19L-1135_Anato";
}