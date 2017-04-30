use MongoDB;
 
my $client     = MongoDB->connect('mongodb://localhost:30000');
my $collection = $client->ns('foo.bar'); # database foo, collection bar

my $j;
for (1..100000) {
    my $result     = $collection->insert_one({ some => 'data' });
}
