<?php
if ($include != TRUE)
	{exit;}
# tagi opisu
$t_description	= array (
					  		  "index"		=> "tworzenie za darmo stron www dla organizacji pozarzadowych, tani hosting dla NGO, domeny na serwisy fundacji i stowarzyszen.", 
					  		  "webmaster"	=> "jako webmaster mo¿esz pomoc fundacjom i stowarzyszeniom dzialajacym dla innych, dajac im swoja wiedze, czas i prace. jako organizacja mo¿ecie mieæ strone www za darmo", 
					  		  "hosting"		=> "niedrogi hosting dla organizacji pozarzadowych z obsluga php, baza danych mysql, poczta elektroniczna i bezplatna domena internetowa", 
					  		  "domena"		=> "bezplatna domena TwojaOrganizacja.3sektor.org dla fundacji i stowarzyszen korzystajacych z programu Hosting dla NGO", 
					  		  "materialy"	=> "materialy szkoleniowe, artykuly na temat tego, jak wykorzystac internet w dzialalnosci organizacji pozarzadowych", 
					  		  "skrypty"		=> "darmowe skrypty, ktore moga przydac siê przy samodzielnym budowaniu stron organizacji pozarzadowych", 
					  		  "jestesmy"	=> "informacje o organizatorach, partnerach i sponsorach programu 3sektor.org realizowanego przez fundacje Kidprotect.pl we wspolpracy z Lap.pl", 
					  		  "kontakt"		=> "kontakt z organizatorami programu 3sektor.org, dane teleadresowe, mail, telefon"
							  );

# tagi slow kluczowy
$t_keywords		= array (
					  		  "index"		=> "internet, organizacje pozarz±dowe, ngo, wsparcie dla sektora, strony www, hosting, serwery wirtualne, domena", 
					  		  "webmaster"	=> "webmaster dla ngo, tworzenie stron www, webmaster, webdesign, kreacja, strony www, html, php, css", 
					  		  "hosting"		=> "hosting serwer wirtualny ftp strona www baza mysql poczta elektroniczna utrzymanie stron www serwery wirtualne", 
					  		  "domena"		=> "domena adres strona www poczta elektroniczna za darmo bezp³atnie darmowa gratis", 
					  		  "materialy"	=> "materia³y poradnik artyku³y edukacyjne rady szkoleniowe porady teksty internet w ngo", 
					  		  "skrypty"		=> "skrypty, php, darmowe, ksiêga go¶ci, forum dyskusyjne, skrypty php, pobierz, download", 
					  		  "jestesmy"	=> "organizatorzy, partnerzy, sponsorzy, kim jeste¶my, kidprotect.pl, lap.pl, fundacja kidprotect.pl", 
					  		  "kontakt"		=> "kontakt z nami email telefon adres"
					  		  );

# tagi tytulu
$t_title			= array (
					  		  "index"		=> "3sektor.org - internet dla organizacji pozarz±dowych", 
					  		  "webmaster"	=> "3sektor.org - Webmaster dla NGO, tworzenie stron www za darmo dla organizacji pozarz±dowych", 
					  		  "hosting"		=> "3sektor.org - Hosting dla NGO, miejsce na stronê www, poczta elektroniczna, email, ftp, obs³uga php, baza danych mysql, serwer wirtualny", 
					  		  "domena"		=> "3sektor.org - bezp³atna domena dla organizacji pozarz±dowych", 
					  		  "materialy"	=> "3sektor.org - bezp³atne materia³y szkoleniowe, edukacyjne i poradniki dla organizacji pozarz±dowych, internet dla NGO", 
					  		  "skrypty"		=> "3sektor.org - darmowe skrypty php, ksiêgi go¶ci, fora dyskusyjne, skrypt", 
					  		  "jestesmy"	=> "3sektor.org - kim jeste¶my, fundacja Kidprotect.pl, Lap.pl, partnerzy, sponsorzy programu", 
					  		  "kontakt"		=> "3sektor.org - kontakt z nami"
					  		  );
if ($_GET ["str"] == "")
	{$strona = "index";}
else
	{$strona = $_GET ["str"];}
$tagi = "
		  <meta name=\"description\" content=\"" . $t_description ["strona"] . "\" />
		  <meta name=\"keywords\" content=\"" . $t_keywords [$strona] . "\" />
		  <title>" . $t_title [$strona] . "</title>
		  ";
?>