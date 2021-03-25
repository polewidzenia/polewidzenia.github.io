<?
function checkFields( $string, $fieldName )
{
	if ( ereg('^[Ee][-]*mail$', $fieldName ) ) {
		if ( !ereg('^.+[@].+\.pl$', $string ) )
			$error .= "Adres e-mail niepoprawny: $string \n";
	} elseif  ( eregi('^.*URL.*$', $fieldName ) )  {
		if ( !ereg('^http://[A-Za-z]*\..+$', $string ) )
			$error .= "Podany adres URL nie jest poprawny: $string \n";
	} elseif  ( ereg('^[Kk]od [Pp]ocztowy$', $fieldName ) )  {
		if ( !ereg('^[0-9][0-9]-[0-9][0-9][0-9]$', $string ) )
			$error .= "Podany kod pocztowy nie jest poprawny: $string \n";
	} elseif  ( ereg('^.*opcjonalne$', $fieldName ) )  {
			$error .= "";
	} else {
		if ( ereg('^[ ]*$', $string ) )
			$error .= "Pole: <b>$fieldName</b> nie moze byc puste \n";
	} 
return $error;	
}
?>