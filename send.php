<HTML>
<HEAD>
<TITLE>Pole Widzenia ��d� Jaskra Badania </TITLE>
<META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=iso-8859-2">
</HEAD>
<BODY BGCOLOR="#D5E5CF" style="margin: 0px">
<?

if ( array_key_exists( "nazwisko", $_POST ) )
	$nazwisko = $_POST["nazwisko"];
if ( array_key_exists( "telefon", $_POST ) )
	$telefon = $_POST["telefon"];
if ( array_key_exists( "ulica", $_POST ) )
	$ulica = $_POST["ulica"];
if ( array_key_exists( "kod", $_POST ) )
	$kod = $_POST["kod"];
if ( array_key_exists( "miasto", $_POST ) )
	$miasto = $_POST["miasto"];

$mail_msg = "Imie i Naziwsko: $nazwisko \n Ulica: $ulica \n Kod: $kod \n Miasto: $miasto \n Telefon $telefon\n\n";
	
$mailheaders = "From: strona@polewidzenia.pl \n";
@mail("tomek@cai.pl", "Zamowienie wizytowek", $mail_msg, $mailheaders);

?>
<?
echo "Imie i nazwisko: $nazwisko <br/> Ulica: $ulica <br/> Kod: $kod <br/> Miasto: $miasto<br/> Telefon: $telefon<br/><br/>";

?>
<p align="justify"><b> Dzi�kujemy za wype�nienie formularza! <br/>Wizyt�wki zostan� wys�ane w najbli�szym czasie.</b></p>

<br/><br/>

</BODY>
</HTML>