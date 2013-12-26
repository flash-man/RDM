<?php
	if (isset($_POST['submit'])) {
		$action = $_POST['radio-choice'];
		$comand_handler = $_POST['user_comand'];
		if ($comand_handler == "green_on") {
			$comand_handler = 4;
		}
		if ($comand_handler == "green_off") {
			$comand_handler = 3;
		}
		$host = "my database host";
		$user = "user name";
		$password = " password";
		$dbname = "database name";
		$connect = mysql_connect($host,$user,$password) or die(mysql_error());
		mysql_select_db($dbname);
		$result = mysql_query ("INSERT INTO comand (id, action, comand_handler) VALUES ('', '$action', '$comand_handler')");
	}

?>