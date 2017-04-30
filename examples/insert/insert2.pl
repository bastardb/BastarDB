use MongoDB;
 
my $client     = MongoDB->connect('mongodb://localhost:30000');
my $collection = $client->ns('foo.bar2'); # database foo, collection bar

my $myhash =
{
    "name"  => "James",
    "age"   => 31,
    #    "likes" => [qw/Danielle biking food games/]
};

my @array;
for (1..100000) {
    push (@array, $myhash);
}

# $collection->batch_insert(\@array);
$res = $collection->insert_many( [ @array ], { ordered => 0 } );

