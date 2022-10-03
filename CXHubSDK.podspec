Pod::Spec.new do |s|
    s.name             = 'CXHubSDK'
    s.version          = '2.0.32'
    s.summary          = 'CXHubSDK implementation.'
    
    s.description      = <<-DESC
    Client SDK for CXHub Mail.ru service.
    DESC
    
    s.homepage         = 'https://cxhub.mail.ru'
    s.license          = { :type => 'LGPL-3.0', :file => 'CXHubSDK/LICENSE' }
    s.author           = { 'CXHub Mail.ru' => 'cxhub@corp.mail.ru' }
    s.source           = { :git => 'https://github.com/cxhub-corp/CXHubSDK.git', :tag => 'v2.0.32' }
    s.ios.deployment_target = '9.0'
    
    s.default_subspec  = ['Core', 'Notify']
    
    s.subspec 'Core' do |sp|
        sp.vendored_frameworks = 'CXHubSDK/CXHubCore.framework'
    end
    
    s.subspec 'Notify' do |sp|
        sp.dependency 'CXHubSDK/Core'
        sp.vendored_frameworks = 'CXHubSDK/CXHubNotify.framework'
        sp.resources = ['CXHubSDK/CXHubNotify.framework/CXHubNotifyResources.bundle']
    end    
end
