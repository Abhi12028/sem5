<?
	$n1=$_GET["n1"];
	$n2=$_GET["n2"];
	$op=$_GET["op"];
	
	function mod($n1,$n2){
		$n3=0;
		if($n2!=)
			$n3=$n1%$n2;
		return $n3;
	}
	
	function power($n1,$n2){
		$n3=$n1**$n2;
		return $n3;
	}
	
	function sum($n1){
		$n3=0
		for($i=1;$i<=$n1;$i++)
			$n3+=$i;
		return $n3;
	}
	
	function fact($n2){
		$n3=1;
		for($i=1;$i<=$n2;$i++)
			$n3=$n3*$i;
		return $n3;
	}
	
	switch ($op){
		case "mod": 
			$result=mod($n1,$n2); 
 			printf("Mod of %d and %d is %d.",$n1,$n2,$result); 
 			break; 
 		case "power":
 			$result=power($n1,$n2); 
 			printf("%d raised to %d is %d.",$n1,$n2,$result); 
			break; 
		case "sum": 
			$result=sum($n1); 
			printf("Sum of first %d number is %d.",$n1,$result); 
			break; 
		case "fact":
			$result=fact($n2); 
			printf("Factorial of %d is %d.",$n2,$result); 
			break; 
	}
?>
