<?
include "form_func.php";

if ( array_key_exists( "mailto", $_POST ) )
	$mailto = $_POST["mailto"];
else
	header("Location: localhost/error.html");

if ( array_key_exists( "subject", $_POST ) )
	$subject = $_POST["subject"];
else
	header("Location: localhost/error.html");
	
if ( array_key_exists( "kod", $_POST ) ) {
	$kod = $_POST["kod"];
	if ( ! ( trim($kod) == $_POST["kod_odp"] ) ) {
		$errors .= "Wpisano bledny token.\n";
	}
} else {
	$errors .= "Bledny token.\n";
}


foreach ( $_REQUEST as $field => $value )
{
	// Nie przetwarzaj ukrytych pol
	if ( $field != "subject" && $field !="mailto" && $field !="kod" && $field != "kod_odp" )
	{
		$field = ereg_replace("_", " ", $field ); // zamien "_" na spacje
		$errors .= checkFields( $value, $field );
		$mail_msg .= "$field :  $value  \n";
		$textHTML .= "<b> $field </b> : &nbsp; $value <br/>";
	}

}

// Gdy nie ma bledow
if ( strlen( trim($errors) ) == 0 )
{
	// HTML
	$title = "Formularz zostal wyslany";
	$opis = "Dane zostaly przeslane do redakcji<br/> Dziekujemy! <br/>";
	$textHTML .= "<br/><br/> <a href='localhost'> strona glówna </a>";	
	
	
	$mailto = ereg_replace("_usunto_", "", $mailto ); // usun "_usunto_" z adresu e-mail 
	
	// MAIL
	$mail_msg .= "\n\n";
    $mailheaders = "From: $mailto \n";
    @mail( $mailto , $subject, $mail_msg, $mailheaders);
} else {
	//HTML
 	$title = "Formularz nie zostal wyslany!";
	$opis = "Niestety formularz zostal <b> blednie </b> wypelniony.<br/> Wróc i popraw ponizsze bledy:";
	$textHTML = "<span style='color: red;'>" . nl2br($errors) . "</span>" . "<br/><br/>  <a href='javascript:history.back();'>wróc i popraw</a>";
}

echo "
<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">
<html>
<head>
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-2\">
<title>Przykladowa Ankieta -  $title </title>
</head>

<body>

<h1> $title </h1>
<p> $opis </p>
<p> $textHTML </p>
</body>
</html>";
?>


