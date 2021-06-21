Pod::Spec.new do |s|
    s.name             = 'CXHubSDK'
    s.version          = '0.0.3'
    s.summary          = 'Libnotify implementation.'
    
    s.description      = <<-DESC
    Client SDK for CXHub Mail.ru service.
    DESC
    
    s.homepage         = 'https://cxhub.mail.ru'
    s.license          = { :type => 'LGPL-3.0', :file => 'CXHubSDK/LICENSE' }
    s.author           = { 'CXHub Mail.ru' => 'cxhub@corp.mail.ru' }
    s.source           = { :git => 'https://github.com/cxhub-corp/CXHubSDK.git', :tag => 'v0.0.3' }
    s.ios.deployment_target = '9.0'
    
    s.default_subspec  = ['Core', 'Notify']
    
    s.subspec 'Core' do |sp|
        sp.vendored_frameworks = 'CXHubSDK/NotifyCore.framework'
    end
    
    s.subspec 'Notify' do |sp|
        sp.dependency 'CXHubSDK/Core'
        sp.vendored_frameworks = 'CXHubSDK/Libnotify.framework'
        sp.resources = ['CXHubSDK/Libnotify.framework/LibnotifyResources.bundle']
    end    
end
