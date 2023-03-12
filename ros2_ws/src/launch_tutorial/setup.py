from setuptools import setup

package_name = 'launch_tutorial'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='migue',
    maintainer_email='duquemigue@gmail.com',
    description='TODO: Package description',
    license='TODO: Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        ],
    },
    data_files=[
      ...
      (os.path.join('share', package_name, 'launch'),
         glob(os.path.join('launch', '*.launch.py'))),
      (os.path.join('share', package_name, 'config'),
         glob(os.path.join('config', '*.yaml'))),
   ],
)
