Pod::Spec.new do |s|
    s.name             = 'CXHubSDK'
    s.version          = '2.0.39'
    s.summary          = 'CXHubSDK implementation.'
    
    s.description      = <<-DESC
    Client SDK for CXHub Mail.ru service.
    DESC
    
    s.homepage         = 'https://cxhub.mail.ru'
    s.license          = { :type => 'LGPL-3.0', :file => 'CXHubSDK/LICENSE' }
    s.author           = { 'CXHub Mail.ru' => 'cxhub@corp.mail.ru' }
    s.source           = { :git => 'https://github.com/cxhub-corp/CXHubSDK.git', :tag => 'v2.0.40' }
    s.ios.deployment_target = '12.1'
    
    s.default_subspec  = ['Core', 'Notify']
    
    s.subspec 'Core' do |sp|
        sp.vendored_frameworks = 'CXHubSDK/CXHubCore.xcframework'
    end
    
    s.subspec 'Notify' do |sp|
        sp.dependency 'CXHubSDK/Core'
        sp.vendored_frameworks = 'CXHubSDK/CXHubNotify.xcframework'
    end    
end
