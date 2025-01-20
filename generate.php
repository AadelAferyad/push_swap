<?php

	function deja_vue($arr, $num)
	{
		if (!$arr)
			return (0);

		foreach ($arr as $x)
		{
			if ($x == $num)
			{
				return (1);
			}
		}
		return (0);
	}
	
	if ($argc < 2)
	{
		echo "Not enough arguments";
		return (0);
	}

	$n = $argv[1];
	$i = 0;
	$arr = [];
	$num;
	$j = 0;
	while ($i < $n)
	{
		$num = rand();
		if (!deja_vue($arr, $num))
		{
			$arr[$j] = $num;
			$j++;
			echo ($num. " ");
		}
		$i++;
	}
	echo "\n";
?>
