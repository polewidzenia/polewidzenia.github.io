<?php
if ($include != TRUE)
	{exit;}

function metaTagi ($t)
			{
			$title			= array (
								  		  "artykul"		=> "artyku� - 3sektor.org - teksty, artyku�y, materia�y, porady, ngo", 
								  		  "domena"		=> "domena - 3sektor.org - darmowa domena, adres strony www", 
								  		  "hosting"		=> "hosting - 3sektor.org - serwery wirtualne, strony www, poczta elektroniczna, php, mysql, hosting", 
								  		  "jestesmy"	=> "kim jeste�my - 3sektor.org - fundacja kidprotect.pl, lap.pl, informacje o organizatorach", 
								  		  "kontakt"		=> "kontakt - 3sektor.org - dane teleadresowe, adresy poczty elektronicznej, telefony",
								  		  "materialy"	=> "materia�y - 3sektor.org - porady, artyku�y, materia�y, internet dla organizacji pozarz�dowych", 
								  		  "skrypty"		=> "skrypty - 3sektor.org - php, ksi�ga go�ci, forum dyskusyjne, darmowe skrypty, system portalowy", 
								  		  "slownik"		=> "s�ownik - 3sektor.org - s�ownik internetu, faq, trudne poj�cia", 
								  		  "webmaster"	=> "webmaster - 3sektor.org - webmaster dla ngo, tworzenie stron www, webdesign, html, css, php, grafika", 
								  		  "index"		=> "3sektor.org - internet dla organizacji pozarz�dowych"
								  		  );
			
			$keywords		= array (
								  		  "artykul"		=> "artyku�, tekst, poradnik, rady, artyku�y, teksty, porada, internet, organizacje pozarz�dowe, ngo", 
								  		  "domena"		=> "domena, strona internetowa, adres, domeny, strona www, organizacje pozarz�dowe, 3sektor, ngo", 
								  		  "hosting"		=> "serwer wirtualny, hosting, poczta elektroniczna, serwery wirtualne, utrzymanie stron, php, mysql, lap.pl, hosting dla ngo", 
								  		  "jestesmy"	=> "organizatorzy, informacje, fundacja kidprotect.pl, 3sektor, internet dla ngo, lap.pl", 
								  		  "kontakt"		=> "kontakt, telefon, adres, email, gadu-gadu, skype, dane teleadresowe, kontakt z nami, pomoc",
								  		  "materialy"	=> "materia�y, teksty, artyku�y, poradnik, s�ownik, porady, internet dla organizacji pozarz�dowych, ngo", 
								  		  "skrypty"		=> "skrypty, php, mysql, ksi�ga go�ci, forum dyskusyjne, newsy, system portalowy, phpbb, joomla, mailing, post nuke, php nuke, systemy portalowe", 
								  		  "slownik"		=> "s�ownik internetu, faq, trudne poj�cia, s�owniczek, materia�y szkoleniowe, encyklopedia", 
								  		  "webmaster"	=> "webmaster, tworzenie stron www, kreacja stron internetowych, html, css, php, mysql, web2.0, blog, webmastering, webdesign, grafika, strona www", 
								  		  "index"		=> "3sektor, ngo, organizacje pozarz�dowe, fundacja, stowarzyszenie, kidprotect, internet dla organizacji, hosting, webmaster, domena, materia�y"
								  		  );
			
			$description	= array (
								  		  "artykul"		=> "materialy szkoleniowe, porady, artykuly na temat wykorzystania internetu w dzialalnosci organizacji pozarzadowych", 
								  		  "domena"		=> "Informacje o mozliwosci bezplatnego skorzystania przez organizacje pozarzadowe z domeny 3sektor.org", 
								  		  "hosting"		=> "Hosting dla NGO to czesc programu 3sektor.org, w ramach ktorej przygotowalismy specjalna, niedroga propozycje hostingu (serwera wirtualnego) dla organizacji pozarzadowych", 
								  		  "jestesmy"	=> "informacje o organizatorze programu 3sektor.org - Fundacji Kidprotect.pl, partnerze hostingowym - Lap.pl oraz o partnerach medialnych i sponsorach", 
								  		  "kontakt"		=> "dane kontaktowe do organizatorow i partnerow programu 3sektor.org realizowanego przez fundacje Kidprotect.pl",
								  		  "materialy"	=> "materialy szkoleniowe, porady, artykuly na temat wykorzystania internetu w dzialalnosci organizacji pozarzadowych", 
								  		  "skrypty"		=> "darmowe skrypty php przydatne dla organizacji pozarzadowych tworzacych swoje strony internetowe", 
								  		  "slownik"		=> "slownik internetu dla organizacji pozarzadowych, czesc strony 3sektor.org stworzonej przez fundacje Kidprotect.pl", 
								  		  "webmaster"	=> "Webmaster dla NGO, webmasterzy tworzacy nieodplatnie strony dla organizacji non-for-profit", 
								  		  "index"		=> "3sektor.org to program fundacji Kidprotect.pl, wspierajacy inne fundacje i stowarzyszenia w wykorzystaniu internetu w ich dzialalnosci"
								  		  );
			$tagi = "<meta name=\"keywords\" content=\"" . $keywords [$t] . "\" />\n";
			$tagi.= "<meta name=\"description\" content=\"" . $description [$t] . "\" />\n";
			$tagi.= "<title>" . $title [$t] . "</title>\n";
			return $tagi;
			}

function czytajSzablon ($tresc)
			{
			$include = TRUE;
			# dolaczenie pliku z tagami
			include "include/naglowki.inc";
			# otwarcie pliku szablonu
			$plik		= "szablon.html";
			$rozmiar	= filesize ($plik);
			$otworz	= fopen ($plik, "r");
			$szablon	= fread ($otworz, $rozmiar);
			fclose ($otworz);
			global $t;
			
			# podstawienie tresci
			$szablon	= str_replace ("[TAGI]", metaTagi($t), $szablon);
			$szablon	= str_replace ("[TRESC]", $tresc, $szablon);
			return $szablon;
			}

function pobierz_RSS ($adres, $folder, $tytul)
			{
			$czas = 1800; // Co ile ma by� aktualizacja
			# $folder = "bufor/"; // Adres folderu, w kt�rym znajdowa� si� b�d� pliki z newsami.
			# $adres = "http://www.webinside.pl/rss.php"; // Adres URL do kana�u RSS
  			$nazwa_kanalu = "<span style=\"font-size: 14px; color: #bb0000\"><img width=\"12\" height=\"12\" alt=\"\" src=\"img/rss.gif\" /> <a href=\""
			  				  . $adres . "\" target=\"_blank\" class=\"red\">"
				 			  . $tytul . "</a></span>"; // Tytu� kana�u RSS
			$liczba = 10; // Ilo�c nag��wk�w news�w, kt�re maj� by� wyswietlane
  			$target = "_blank"; // Opcja target="" dla news�w, mo�liwe: "_self" oraz "_blank"
  			$autoupdate = TRUE;
  			$trunc = FALSE;
  			$delim = FALSE;
  
  			if (isset ($_GET ['rssHeadline']) )
				{$rssHeadline = $_GET ['rssHeadline'];}
  			$basefile = $folder;
  			$folder .= md5($adres).".htm"; // Przygotowywanie nazw plik�w dla danego kana�u

  			#==========================
  			# Operacje zwiazane ze sprawdzaniem aktualnosci nag��wk�w w pliku tekstowym
  			#==========================

  			if (($czas > 0) && (is_file($folder)) && (((time()-filemtime($folder)) < ($czas * 60))))
			  	{
  				$tresc = file ($folder);
    			return implode (" ",$tresc);
				} 
  			elseif (@fopen ($adres,"r"))
			   {
				// Sprawdza czy ma dost�p do kana�u RSS

  	  			# ==========================
	  			# Operacja zwiazane z dodawaniem nowego nag��wka do pliku
	  			# ==========================

	  			$rssHandle = fopen ($adres,"r") ; // Otwiera plik kana�u RSS
      		$rssData = '';
	  			while (!feof ($rssHandle))
						{$rssData .= fgets ($rssHandle);}

	  			# ==========================
	  			# Przygotowywanie newsa do w��czenia do pliku
	  			# ==========================
	  			$tag = "item ";
	  			$rssData =  preg_replace("/<" . $tag . "(.|\s)*?>/","<item>",$rssData);
	  			$rssData = chop($rssData); // Usuwanie pustych spacji z ko�ca linijek   
	  			$rssData = ereg_replace("[\r,\n]", "", $rssData); // Usuwwanie pustych linijek
	  			$rssData = strstr($rssData,"<item>"); // Usuwanie wszystie przez <item>.

	  			# ==========================
	  			# Usuwanie zb�dnych elemnt�w tak aby okrojona zawarto�� mog�a zosta� zapisana w pliku

	  			# Tagi <description></description> zostaj� pomini�te
	  			# ==========================	  
	  			$tags_and_content_to_strip = Array("description");

	  			foreach ($tags_and_content_to_strip as $tag) {
	       	$rssData = preg_replace("/<" . $tag . ">(.|\s)*?<\/+" . $tag . ">/","",$rssData);
	  			}

	  			$rssData = str_replace("<item>","", $rssData); // usuwanie tagu <item>
	  			$rssData = urldecode($rssData); // Zamiana wszystkich: %20 na spacje.
	  			$rssData = str_replace(strstr("</channel>",$rssData),"",$rssData);
	  			$rssArray = explode("</item>",$rssData); // Tworzenie tablicy z nag��wkami
  
  	  			$title = array();
	  			$link = array();

	  			#==========================
	  			# Ten mechanizm tworzy tablice dla link�w oraz nag��wk�w
	  			#==========================  
	  			$x = 0;
	  	  		while($x < $liczba) {
  				$link[$x] = strstr($rssArray[$x],"<link>"); // usuwanie wszystkiego przed <link>
				$link[$x] = ereg_replace("<link>","",$link[$x]); 
 				$link[$x] = str_replace(strstr($link[$x],"</link>"),"",$link[$x]);
	 			$link[$x] = trim($link[$x]);
				$link[$x] = str_replace(" ","+",$link[$x]);

				$title[$x] = strstr($rssArray[$x],"<title>");
  				$title[$x] = ereg_replace("<title>","",$title[$x]); // Usuwanie <title> z cz�ci tytu�u newsa
	  			$title[$x] = str_replace(strstr($title[$x],"</title>"),"",$title[$x]); //  Usuwanie </title> oraz wszystkiego poza nim
	  			$title[$x] = trim($title[$x]);
		
				if ($trunc != FALSE) { $title[$x] = str_replace(substr($title[$x],$trunc),"",$title[$x]); }
				if ($delim != FALSE) { $title[$x] = str_replace(strstr($title[$x],$delim),"",$title[$x]); }
        
        		if ($title[$x] == "") { $liczba = $x; break; } // Gdy ju� nie ma nag��wk�w zmienna $liczba przyjmuje warto�� maksymaln�.
				$x++;
	  			}

	  			#==========================
	  			# Zapis do pliku
	  			#==========================
	  			$fp = fopen($folder, "w+");
	  			$x=0;  
	  			fwrite($fp,"<b><span class=\"displayname\">$nazwa_kanalu</span></b> \n"); // zapisywanie do pliku

	  			while ($x < $liczba) { // ta p�tla zapisuje ka�dy link osobno.
  				fwrite($fp,"<br>\n+ <a class=\"headlinellink\" target=\"$target\" title=\"$title[$x]\" href=\"$link[$x]\">$title[$x]</a>");
				$x++;
	  			}
	 			fclose($fp);

  				$tresc=file($folder);
    			return implode(" ",$tresc);


  				}
			else
				{ 
				#==========================
				# Zwracanie b��du gdy podany adres jest b��dny.
				#==========================
				return "<b>Nie mozna po��czy� si� z adresem: $adres. </b>";

 				}
			}

function pobierz_TXT ($txt)
			{
			$plik		= "txt/" . $txt . ".txt";
			$rozmiar	= filesize ($plik);
			$otworz	= fopen ($plik, "r");
			$czytaj	= fread ($otworz, $rozmiar);
			fclose ($otworz);
			$czytaj	= nl2br ($czytaj);
			$czytaj	= str_replace ("[b]", "<span style=\"font-weight: bold;\">", $czytaj);
			$czytaj	= str_replace ("[/b]", "</span>", $czytaj);
			$czytaj	= str_replace ("[r]", "<span style=\"color: #bb0000;\">", $czytaj);
			$czytaj	= str_replace ("[/r]", "</span>", $czytaj);
			$czytaj	= str_replace ("[24]", "<span style=\"font-size: 24px;\">", $czytaj);
			$czytaj	= str_replace ("[/24]", "</span>", $czytaj);
			$czytaj	= str_replace ("[14]", "<span style=\"font-size: 14px;\">", $czytaj);
			$czytaj	= str_replace ("[/14]", "</span>", $czytaj);
			$czytaj	= str_replace ("[p]", "<span style=\"color: #ff5500;\">", $czytaj);
			$czytaj	= str_replace ("[/p]", "</span>", $czytaj);
			return $czytaj;
			}

function pobierz_ART ($txt)
			{
			$plik		= "txt/" . $txt . ".txt";
			$rozmiar	= filesize ($plik);
			$otworz	= fopen ($plik, "r");
			$czytaj	= fread ($otworz, $rozmiar);
			fclose ($otworz);
			list ($tytul, $tekst) = explode ("|", $czytaj);
			$tekst	= nl2br ($tekst);
			$tekst	= str_replace ("[b]", "<span style=\"font-weight: bold;\">", $tekst);
			$tekst	= str_replace ("[/b]", "</span>", $tekst);
			$tekst	= str_replace ("[r]", "<span style=\"color: #bb0000;\">", $tekst);
			$tekst	= str_replace ("[/r]", "</span>", $tekst);
			$tekst	= str_replace ("[24]", "<span style=\"font-size: 24px;\">", $tekst);
			$tekst	= str_replace ("[/24]", "</span>", $tekst);
			$tekst	= str_replace ("[14]", "<span style=\"font-size: 14px;\">", $tekst);
			$tekst	= str_replace ("[/14]", "</span>", $tekst);
			$tekst	= str_replace ("[p]", "<span style=\"color: #ff5500;\">", $tekst);
			$tekst	= str_replace ("[/p]", "</span>", $tekst);
			$artykul = "<h1>" . $tytul . "</h1><p>" . $tekst . "</p>";
			return $artykul;
			}
?>