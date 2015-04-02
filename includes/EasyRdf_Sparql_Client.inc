<?php

class EasyRdf_Sparql_Client2 extends EasyRdf_Sparql_Client {

	public function insert($data, $graphUri = null)
	{
	    $query = 'INSERT INTO ';
	    if ($graphUri) {
	        $query .= "GRAPH <$graphUri> {";
	    }
	    $query .= $this->convertToTriples($data);
	    if ($graphUri) {
	        $query .= "}";
	    }
	    return $this->request('query', $query);
	}

    public function clear($graphUri, $silent = false)
    {
        $query = "CLEAR";
        if ($silent) {
            $query .= " SILENT";
        }
        if (preg_match('/^all|named|default$/i', $graphUri)) {
            $query .= " $graphUri";
        } else {
            $query .= " GRAPH <$graphUri>";
        }
	    return $this->request('query', $query);
    }
}


