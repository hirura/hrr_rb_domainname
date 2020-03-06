RSpec.describe HrrRbDomainname do
  it "has a version number" do
    expect(HrrRbDomainname::VERSION).not_to be nil
  end

  describe ".get" do
    it "returns domainname" do
      expect(HrrRbDomainname.get).to eq `domainname`.chomp
    end
  end

  describe ".getdomainname" do
    it "returns domainname" do
      expect(HrrRbDomainname.getdomainname).to eq `domainname`.chomp
    end
  end

  describe ".set" do
    before :example do
      @name_bak = `domainname`.chomp
    end

    after :example do
      `domainname "#{@name_bak}"`
    end

    let(:name){ "new#{@name_bak}" }

    it "sets domainname and returns it" do
      expect(HrrRbDomainname.set(name)).to eq name
      expect(`domainname`.chomp).to eq name
    end
  end

  describe ".setdomainname" do
    before :example do
      @name_bak = `domainname`.chomp
    end

    after :example do
      `domainname "#{@name_bak}"`
    end

    let(:name){ "new#{@name_bak}" }

    it "sets domainname and returns it" do
      expect(HrrRbDomainname.setdomainname(name)).to eq name
      expect(`domainname`.chomp).to eq name
    end
  end
end
