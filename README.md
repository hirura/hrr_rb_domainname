# HrrRbDomainname

[![Build Status](https://travis-ci.com/hirura/hrr_rb_domainname.svg?branch=master)](https://travis-ci.com/hirura/hrr_rb_domainname)

hrr_rb_domainname is a wrapper around getdomainname and setdomainname for CRuby.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'hrr_rb_domainname'
```

And then execute:

    $ bundle install

Or install it yourself as:

    $ gem install hrr_rb_domainname

## Usage

The basic usage is as follows.

```ruby
require "hrr_rb_domainname"

HrrRbDomainname.get                 # => "currentdomainname"
HrrRbDomainname.set "newdomainname" # => "newdomainname"
HrrRbDomainname.get                 # => "newdomainname"
```

### Getting domainname

The .get and .getdomainname methods return the current domainname as same as domainname command.

```ruby
HrrRbDomainname.get           # => "currentdomainname"
HrrRbDomainname.getdomainname # => "currentdomainname"
```

#### Setting domainname

The .set and .setdomainname methods set domainname and return the set domainname.

```ruby
HrrRbDomainname.set "newdomainname"           # => "newdomainname"
HrrRbDomainname.setdomainname "newdomainname" # => "newdomainname"
```

## Development

After checking out the repo, run `bin/setup` to install dependencies. Then, run `rake spec` to run the tests. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/hirura/hrr_rb_domainname. This project is intended to be a safe, welcoming space for collaboration, and contributors are expected to adhere to the [code of conduct](https://github.com/hirura/hrr_rb_domainname/blob/master/CODE_OF_CONDUCT.md).


## License

The gem is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT).

## Code of Conduct

Everyone interacting in the HrrRbDomainname project's codebases, issue trackers, chat rooms and mailing lists is expected to follow the [code of conduct](https://github.com/hirura/hrr_rb_domainname/blob/master/CODE_OF_CONDUCT.md).
